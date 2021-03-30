SELECT n.hacker_id, n.name, SUM(n.score)
FROM(SELECT sub.hacker_id, hac.name, sub.score
    FROM (SELECT hacker_id, MAX(score) as score
        FROM submissions
        GROUP BY hacker_id, challenge_id) as sub
    LEFT JOIN hackers AS hac ON sub.hacker_id = hac.hacker_id) as n
GROUP BY n.hacker_id, n.name
HAVING SUM(n.score) != 0
ORDER BY SUM(n.score) DESC, n.hacker_id ASC