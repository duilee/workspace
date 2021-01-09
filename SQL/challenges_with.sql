WITH counter AS (
    SELECT hackers.hacker_id
        , hackers.name
        , COUNT(*) AS challenges_created
    FROM challenges
        INNER JOIN hackers ON challenges.hacker_id = hackers.hacker_id
    GROUP BY hackers.hacker_id, hackers.name
)

SELECT counter.hacker_id, 
        counter.name, 
        counter.challenges_created
FROM counter
WHERE challenges_created = (SELECT MAX(challenges_created) FROM counter)
OR challenges_created IN (SELECT challenges_created
                          FROM counter
                          GROUP BY challenges_created
                          HAVING COUNT(*) = 1)
ORDER BY counter.challenges_created DESC, counter.hacker_id