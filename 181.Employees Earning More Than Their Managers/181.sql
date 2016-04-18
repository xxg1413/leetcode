select e1.Name as Employee from Employee e1 join Employee e2 on e1.ManagerID=e2.Id where e1.Salary > e2.Salary
