with A as (
    SELECT DISTINCT visited_on
    from customer
)



SELECT A.visited_on, SUM(B.amount) AS amount, ROUND(SUM(B.amount)/7, 2) AS average_amount
FROM A INNER JOIN customer B 
ON DATEDIFF(A.visited_on, B.visited_on) <= 6 and A.visited_on >= B.visited_on
GROUP BY A.visited_on
ORDER BY A.visited_on
LIMIT 99999999999999 OFFSET 6;