# Write your MySQL query statement below
SELECT w1.id
FROM weather as w1
    INNER JOIN weather as w2
            ON w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY)
WHERE w1.Temperature > w2.Temperature
