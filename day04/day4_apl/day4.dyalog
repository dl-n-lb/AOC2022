input ← ⊃⎕nget '../in.txt' 1
ranges ← ⍎¨¨¨{'-' (≠⊆⊢) ⍵}¨¨','(≠⊆⊢)¨input
o ← {⍵[⍒⍵]}

+/{c ← (⊃⊃⍵) = (⊃⊃1↓⍵)⋄c ∨ 0≥1↓⊃-/o⍵}¨ranges ⍝ Part A

+/{⊃⊃⍵ ≤ ⊃1↓⊃1↓⍵}¨{o⍵}¨ranges ⍝ Part B
