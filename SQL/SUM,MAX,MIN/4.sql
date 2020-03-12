--- 중복되는 이름은 하나로 치고 NULL인 경우는 집계하지 않는다.---
SELECT COUNT(DISTINCT(NAME))
FROM ANIMAL_INS
WHERE 1=1
--- COUNT(*)은 NULL값 포함. COUNT(column)은 NULL값 제외 ---