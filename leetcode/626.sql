-- 奇数 + 1，偶数 - 1，加上最后一个奇数
-- union 会做数据去重，并按返回结果的第一列进行默认排序
-- union all 直接做拼接
SELECT (ID + 1) as ID, STUDENT
WHERE
    MOD(ID, 2) = 1 AND
    ID != (SELECT COUNT(1) FROM SEAT)

UNION ALL

    SELECT (ID - 1) as ID, STUDENT
    WHERE MOD(ID, 2) = 0

UNION ALL

    SELECT ID, STUDENT
    WHERE
        MOD(ID, 2) = 1 AND
        ID = (SELECT COUNT(1) FROM SEAT)

ORDER BY ID

-- 题解: SELECT CASE WHEN

SELECT
    (CASE
        WHEN MOD(ID, 2) != 0 AND COUNTS != ID THEN ID + 1
        WHEN MOD(ID, 2) != 0 AND COUNTS = ID THEN ID
        ELSE ID - 1
    END) AS ID, STUDENT
FROM
    SEAT,
    (SELECT
        COUNT(1)
     AS COUNTS
     FROM SEAT) AS SEAT_COUNTS
ORDER BY ID;
