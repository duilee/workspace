# Write your MySQL query statement below
SELECT emp1.name AS 'Employee'
FROM employee AS emp1
INNER JOIN employee AS emp2
        ON emp1.managerid = emp2.id
WHERE emp1.salary > emp2.salary