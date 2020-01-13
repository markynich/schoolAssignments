;Homework 6 Scheme Function

;Binomial function
; calculates binomial coefficent
(define (C N k)
  (cond
  	[(= N k) 1]
  	[(= k 0) 1]
  	[(+ (C (- N 1) k) 
        (C (- N 1) (- k 1)))]
  )
);end of binomial convertor

(print "Binomial Function\n(C 10 9) = "(C 10 9))
(print "(C 10 7) = "(C 10 7)"\n\n")


;mod is already defined in Scheme to get the modulus value
;Created function Mod which uses mod to get modulus value
(define (Mod M N) (mod M N))

(print "Mod Function\n(Mod 17 5) = "(Mod 17 5))
(print "(Mod 34 6) = "(Mod 34 6)"\n\n")


;Binary to Decimal Function
;converts binary bits to Decimal value
(define (binaryToDecimal b)
  (cond
  	;base case: return 0 if bit is 0
  	[(= b 0) 0]
  	;recursve: go through binary bits and
  			  ;convert to decimal
  	[(+ (Mod b 10) 
    (* (binaryToDecimal (floor (/ b 10))) 2))]
  )
);end of binaryToDecimal

(print "binaryToDecimal Function\n(binaryToDecimal 1010) = "(binaryToDecimal 1010))
(print "(binaryToDecimal 10110) = "(binaryToDecimal 10110)"\n\n")

;converts binary bits from the list to decimal
;and adds the sum of the list
(define (addBinary binaryList)
  (cond
  	;base case: return 0 when reach at end of list
  	[(null? binaryList) 0]
  	;recursive: go through list and convert values
  	[(+ (binaryToDecimal(car binaryList)) 
      	(addBinary (cdr binaryList)))]
  )
);end of addBinary

(print "addBinary Function\n(addBinary '(1101 0110 01 10)) = "(addBinary '(1101 0110 01 10)))
(print "(addBinary '(1111 0110 0100 1010 1)) = "(addBinary '(1111 0110 0100 1010 1))"\n\n")


;uses built in function min to get the minimum value
;but reads a list of integers, not multiple parameters
(define (Min intList)
  (min (car intList)
  	;recursive: find minimum value from the list
    (if (not (null? (cdr intList)))
    	;then statement | #t
     	(Min (cdr intList))
     	;else statement | #f
     	(car intList)
    )
  )
);end of Min function

(define valList1 '(40 56 88 19 2 28 63))
(define valList2 '(100 18 4 92 18 1 43 19 70 24))
(print "creating list: valList1 = " valList1)
(print "creating list: valList2 = " valList2 "\n")
(print "Min Function\n(Min valList1) = "(Min valList1))
(print "(Min valList2) = "(Min valList2)"\n\n")


;removes the passing parameter "num" from the passing
;parameter "numList"
;num must be a value while numList must be a list of values
(define myRemove
  (lambda (num numList)
    (cond
     ;base case 1: if num exists
     [(equal? num (car numList)) (cdr numList)]
     ;base case 2: if num doesn't exist
     [(null? (cdr numList)) numList]
     ;recursive: search through the list
     [(cons (car numList) (myRemove num (cdr numList)))
     ]
    )
  )
);end of myRemove

(print "using list: valList1 = " valList1 "\n")
(print "myRemove Function\n(myRemove 56 valList1) = "(myRemove 56 valList1))
(print "(myRemove 99 valList1) = "(myRemove 99 valList1)"\n\n")

;takes in a list of values and sorts them from
;lowest to greatest
(define (selectionSort list)
	(cond
		;base case: return last element back to list
		[(null? (myRemove (Min list) list)) list]
		;recursive: sort list from min to max
		[(cons (Min list) 
		(selectionSort 
			(cdr (cons (Min list) 
            (myRemove (Min list) list)));inner cons & cdr
        )
		)]
	)
);end of selectionSort

(print "using list: valList1 = " valList1)
(print "using list: valList2 = " valList2)
(print "\nselectionSort Function\n(selectionSort valList1) = "(selectionSort valList1))
(print "(selectionSort valList2) = "(selectionSort valList2)"\n\n")
(print "end of program")