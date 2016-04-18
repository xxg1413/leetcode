SELECT DISTINCT t.`Num` FROM (
      SELECT `Num`, @prev := @curr, @curr := `Num`, @count := IF(@prev = @curr, @count + 1, 1) AS Count
      FROM Logs, (SELECT @curr := null, @prev := null, @count := 1) sel1) t WHERE t.Count >= 3
