⍝ WORSE SOLUTION
alpha ← 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
h ← {((≢⍵)÷2) {(⍺↑⍵) (⍺↓⍵)} ⍵ } ⍝ split each list in half
eq_char ← {c ← ⍺ ⋄ ⊃ ⊃,/{ c { c[⍸⍵=c] } ⍵ }¨⍵ } ⍝ find the equal character between two strings
eq_char ← {⊃((⊃⍵[0])∩(⊃⍵[1]))} ⍝ alternative form using set operation (how did i miss this)
input ← ⊃⎕NGET '../in.txt' 1
halves ← h¨input
items ← {(⊃⍵[0]) eq_char (⊃⍵[1])}¨halves
+⌿((alpha⍳items) + 1)  ⍝ result (= sum reduction over the indices of items in alpha)


⍝ BETTER SOLUTION

alpha ← 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
h ← {((≢⍵)÷2) {(⍺↑⍵) (⍺↓⍵)} ⍵ } ⍝ split each list in half
input ← ⊃⎕NGET '../in.txt' 1

+⌿((alpha⍳{⊃⊃∩⌿⍵}¨h¨input) + 1)

+⌿((alpha⍳{⊃⊃∩⌿⍵}¨↓((3÷⍨≢input) 3 ⍴ input))+1) ⍝ Part B
