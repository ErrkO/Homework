#lang racket

;Eric Oliver
;CSCI 4230
;Assignment 4

; definitions for testing
(define el '())
(define onel '(1))
(define poly1 '(2 3 1 0 5))
(define bigl '(1 2 3 4 5 6 7 8 9 10))
(define evenl '(2 4 6 8 10))
(define oddl '(1 3 5 7 9))
(define unsort '(2 7 4 9 8 3 5 1 6 10))

;function to determine lettergrade based on score out of 100
(define lettergrade
  (lambda (num)
    (if (< num 0)
      (display "number out of range")
      (if (< num 60)
        (display "Grade: F")
        (if (< num 70)
          (display "Grade: D")
          (if (< num 80)
            (display "Grade: C")
            (if (< num 90)
              (display "Grade: B")
              (if (<= num 100)
                (display "Grade: A")
                (display "Number out of range")))))))))

;Non recursive function to countdown to blastoff
(define countdown
  (λ (timer)
    (do ()
      ((<= timer 0))
      (display timer)
      (display "\n")
      (set! timer (- timer 1)))
    (display "Blastoff!")))

;recursive function to solve a polynomial given a list of coeficients and an x value
(define eval-poly
  (λ (coeflist xval)
    (if (null? coeflist)
      0
      (+ (car coeflist) (* xval (eval-poly (cdr coeflist) xval))))))

;tail recursive function to do the same as above
(define eval-poly-tail
  (λ (coeflist xval)
    (eval-poly-tail-helper coeflist xval 0)))

;Tail recursion helper for eval-poly-tail
(define eval-poly-tail-helper
  (λ (coeflist xval expo)
    (if (null? coeflist)
      0
      (if (= expo 0)
        (+ (car coeflist) (eval-poly-tail-helper (cdr coeflist) xval (+ expo 1)))
        (+ (* (car coeflist) (expt xval expo)) (eval-poly-tail-helper (cdr coeflist) xval (+ expo 1)))))))
      
;Function to split a list into 2 almost equal lists
(define split
  (λ (L)
    (cons (odd L) (cons (even L) '()))))

;Helper function for split
(define odd
  (λ (L)
    (if (null? L)
      '()
      (if (null? (cdr L))
        (list (car L))
        (cons (car L) (odd (cddr L)))))))

;helper function for split
(define even
  (λ (L)
    (if (null? L)
      '()
      (if (null? (cdr L))
        '()
        (cons (cadr L) (even (cddr L)))))))

;Function to merge two lists into 1
(define merge
  (λ (L L2)
    (if (null? L)
      L2
      (if (null? L2)
        L
        (if (< (car L) (car L2))
          (cons (car L) (merge (cdr L) L2))
          (cons (car L2) (merge (cdr L2) L)))))))

;Function that uses split and merge to sort a list of numbers
(define mergesort
  (λ (L)
    (if (null? L)
      '()
      (if (null? (cdr L))
        L
        (merge (mergesort (car (split L))) (mergesort (cadr (split L))))))))