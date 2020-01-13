(define (avg L) 
  (/ (apply + L) (length L))
)

(define (stdev L)
  (let ((a (avg L)))
    (sqrt
      (
        /
        (apply + 
          (map
            (lambda (elem) 
              (* (- elem a) (- elem a))
            )
            L
          )
        )
        (- (length L) 1)
      )
    )
  )
)