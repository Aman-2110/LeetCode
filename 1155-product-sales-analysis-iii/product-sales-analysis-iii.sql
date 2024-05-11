-- # Write your MySQL query statement below

-- # product id, year, quantity, and price 
-- # first year of every product sold


-- SELECT product_id, year AS first_year, quantity, price
-- FROM Sales
-- WHERE (product_id, year) in (
--     SELECT product_id, MIN(year) 
--     FROM Sales
--     GROUP BY product_id
-- )


WITH MIN_YEAR_FOR_EACH_PRODUCT AS (
    SELECT product_id, min(year) as year
    FROM Sales
    GROUP BY product_id
)

SELECT A.product_id, A.year as first_year, A.quantity, A.price
FROM Sales A INNER JOIN MIN_YEAR_FOR_EACH_PRODUCT B
ON A.product_id = B.product_id AND A.year = B.year