; Красноперов Виталий Сергеевич
; Функциональное программирование
; Лабораторная работа #2
; Вариант 1


; 1. Определите функцию, зависящую от одного аргумента, которая по данному
; списку вычисляет список его элементов, встречающихся в нем более одного
; раза. Проверьте, как она будет работать на примере '(a a a a b a).
(defun f1 (lst &optional acc)
  (if lst
    ((lambda (head tail)
      (f1 tail
       (if (member head acc)
         acc
         (if (member head tail)
           (cons head acc)
           acc))))
    (car lst)
    (cdr lst))
    (reverse acc)))

; > (f1 '(a a a b b a))
; (A B)


; 2. Определите функцию, зависящую от двух аргументов u и n, которая по
; данному списку строит список его элементов, встречающихся в нем не менее
; n раз. Проверьте работу этой функции на примере (a a b a c b c a b b d a b) для
; n=1,2,5,0.
(defun f2 (u n &optional acc)
  (if u
    ((lambda (head tail)
      (f2 tail n ((lambda (link)
        (if link
          (subst (cons (car link) (1+ (cdr link))) link acc :test 'EQUAL)
          (cons (cons head 1) acc)))
        (assoc head acc))))
    (car u)
    (cdr u))
   (apply 'append
     (mapcar (lambda (e) (if (>= (cdr e) n) (cons (car e) nil))) (reverse acc)))))

; > (f2 '(a a b a c b c a b b d a b) 1)
; (A B C D)
; > (f2 '(a a b a c b c a b b d a b) 2)
; (A B C)
; > (f2 '(a a b a c b c a b b d a b) 5)
; (A B)
; > (f2 '(a a b a c b c a b b d a b) 0)
; (A B C D)

; 3. Используя функционалы, напишите функцию, которая из данного списка
; строит список списков его элементов, например, (a b) -> ((a) (b)).
(defun f3 (l)
  (mapcar #'list l))

; > (f3 '(a b))
; ((A) (B))
