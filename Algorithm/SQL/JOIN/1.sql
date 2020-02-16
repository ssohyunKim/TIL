-- A에는 존재하지만 B에는 없는 것 A-(A∩B) --
SELECT A.ANIMAL_ID, A.NAME
FROM ANIMAL_OUTS AS A 
LEFT JOIN ANIMAL_INS AS B
ON A.ANIMAL_ID = B.ANIMAL_ID
WHERE B.ANIMAL_ID IS NULL