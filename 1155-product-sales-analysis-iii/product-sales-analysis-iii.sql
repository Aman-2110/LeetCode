SELECT A.product_id, A.year as first_year, A.quantity, A.price
FROM Sales A INNER JOIN (
    SELECT product_id, min(year) as year
    FROM Sales
    GROUP BY product_id
) B
ON A.product_id = B.product_id AND A.year = B.year