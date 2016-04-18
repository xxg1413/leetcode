SELECT t.Score, t.Rank FROM (SELECT Score, @prev := @curr, @curr := Score, @rank := IF(@prev = @curr, @rank, @rank + 1) AS Rank
    FROM Scores, (SELECT @curr := null, @prev := null, @rank := 0) sel1 ORDER BY Score DESC) t
