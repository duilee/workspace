# Write your MySQL query statement below
SELECT DISTINCT t1.num AS ConsecutiveNums
FROM Logs AS t1
INNER JOIN Logs AS t2 ON t2.id = t1.id +1
INNER JOIN Logs AS t3 ON t3.id = t1.id +2
WHERE t1.num = t2.num AND t2.num = t3.num