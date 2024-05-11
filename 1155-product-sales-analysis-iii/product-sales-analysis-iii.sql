SELECT product_id, year as first_year, quantity, price
FROM Sales NATURAL JOIN (
    SELECT product_id, min(year) as year
    FROM Sales
    GROUP BY product_id
) B
-- ON A.product_id = B.product_id AND A.year = B.year