#lang racket

(define slope
  (lambda (a b) (/ a b)))

(define (sqaure? a)
  (if (sqrt a