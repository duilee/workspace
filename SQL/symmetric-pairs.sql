SELECT x, y
FROM functions
WHERE X = Y
GROUP BY X, Y
HAVING COUNT(*) = 2

UNION

SELECT f1.x, f1.y
FROM functions AS f1
    INNER JOIN functions AS f2 ON f1.x = f2.y AND f1.y = f2.x
WHERE f1.x < f1.y
ORDER BY x