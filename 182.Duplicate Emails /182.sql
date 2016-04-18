SELECT DISTINCT t1.Email FROM Person t1 JOIN Person t2 ON t1.Email = t2.Email AND t1.Id < t2.Id
