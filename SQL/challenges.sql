SELECT hackers.hacker_id
    , hackers.name
    , COUNT(*) AS challenges_created
FROM challenges
    INNER JOIN hackers ON challenges.hacker_id = hackers.hacker_id
GROUP BY hackers.hacker_id, hackers.name
HAVING challenges_created = (SELECT MAX(challenges_created)
                            FROM(
                                SELECT hacker_id, COUNT(*) AS challenges_created
                                FROM challenges
                                GROUP BY hacker_id) sub)
-- If more than one student created the same number of challenges and the count is less than the maximum number of challenges created, then exclude those students from the result.
OR challenges_created IN (SELECT challenges_created
                            FROM(
                                SELECT hacker_id
                                    , COUNT(*) as challenges_created
                                FROM challenges
                                GROUP BY hacker_id
                            ) sub
                            GROUP BY challenges_created
                            HAVING COUNT(*) = 1)

ORDER BY challenges_created DESC, hacker_id