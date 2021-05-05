
WITH totalTable AS (
	SELECT d.id
	     , CASE
		   WHEN SUM(e.salary) IS NULL THEN 0
		   ELSE SUM(e.salary) / COUNT(DISTINCT e.id)
		   END AS 'AverageSalary'
	     /* USE IFNULL() to set e.id to 0 if NULL, all is null, total count is 0 */
	     , CASE
		   WHEN SUM(IFNULL(e.id, 0)) = 0 THEN 0
	           ELSE COUNT(e.id)
		   END AS 'employeeCount'
	FROM departments d
	LEFT JOIN employees ON e.departmentid = d.id
	GROUP BY d.id

)


SELECT departmentId
     , AverageSalary
     , CASE
           WHEN (SELECT SUM(salary) / COUNT(DISTINCT id) FROM employees) > AverageSalary OR
                employeeCount = 0  THEN 'Below'
           WHEN (SELECT SUM(salary) / COUNT(DISTINCT id) FROM employees) < AverageSalary THEN 'Above'
           ELSE 'Equal'
           END AS 'status'
FROM totalTable