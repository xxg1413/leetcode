SELECT t3.Name AS Department, t1.Name AS Employee, t1.Salary AS Salary
FROM Employee t1
JOIN (SELECT DepartmentId, max(Salary) AS Salary FROM Employee GROUP BY DepartmentId) t2 ON t1.DepartmentId = t2.DepartmentId AND t1.Salary = t2.Salary
JOIN Department t3 ON t1.DepartmentId = t3.Id
