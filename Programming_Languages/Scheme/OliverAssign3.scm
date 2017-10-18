;#lang r5rs
#lang racket

; Eric Oliver

(require rnrs/mutable-pairs-6)
;(require srfi/41)  

;list definitions for testing
(define l '(2 3 2))
(define l2 '(3 2 4))
(define ol '(3 5 7))
(define bigl '(1 2 3 4 5 6 7 8 9 10))
(define el '())
(define num 11)
(define rl '(1 5 32 9 302 -103 20 -203 -249 393))
(define dl '(1 2 3 1 3 4 5))

;slope function
(define slope
  (lambda (a b) (/ a b)))

;square predicate
(define square?
  (lambda (a)
    (if (integer? (sqrt a))
      "#t" "#f")))

;replace first function
(define replace-first
  (lambda (ml a)
    (if (null? ml)
      '()
    (cons a (cdr ml)))))

;replace first bang
(define replace-first!
  (lambda (ml a)
    (if (null? ml)
      '() 
    (set-car! ml a))))

; all odd predicate
(define all-odd?
  (lambda (ml)
    (define counter 0)
    (define len (length ml))
    (if (null? ml)
      (display "#f") (begin
      (for-each (lambda (ml2)
        (if (odd? ml2)
          (set! counter (+ 1 counter)) (set! counter (+ 2 counter))))
        ml)
      (if (= counter len)
        (display "#t") (display "#f"))))))
      
; filter odd function
(define filter-odd
  (lambda (ml)
    (if (null? ml)
      '()
      (begin
        (if (odd? (car ml))
          (cons (car ml) (filter-odd (cdr ml)))
          (filter-odd (cdr ml)))))))

;product function
(define product
  (lambda (ml)
    (if (null? ml)
      '()
      (* (car ml) (ph (cdr ml) 1)))))

;product function helper
(define ph
  (lambda (ml i)
    (if (null? ml)
      (if (= i 1)
        1
        (* (car ml) (ph (cdr ml) 1)))
      (* (car ml) (ph (cdr ml) 1)))))

;finding the smallest value
(define smallest
  (lambda (ml small)
    (if (null? ml)
      small
      (if (< (car ml) small)
        (smallest (cdr ml) (car ml))
        (smallest (cdr ml) small)))))

;remove first value
(define remove-first
  (lambda (ml num)
    (if (null? ml)
      '()
    (if (= (car ml) num)
      (cdr ml)
      (cons (car ml) (remove-first (cdr ml) num))))))

; selection sort algorithm
(define selection-sort
  (lambda (ml)
    (if (null? ml)
      '()
      (cons (smallest ml (car ml)) (selection-sort (remove-first ml (smallest ml (car ml))))))))