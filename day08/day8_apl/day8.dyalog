in ← ⊃⎕nget '../in.txt' 1
t ← ⍎¨↑in
s ← ≢t
fn ← {q←⍵⋄{(s 1⍴1↑⍉⍵⌽q) > s 1⍴⌈⌿⍵↑⍉q}¨1-⍨⍳s}
wf ← {⍉s s⍴↑fn ⍵}
sfn ← {(wf ⍵) ∨ (⌽wf ⌽⍵) ∨ (⍉wf ⍉⍵) ∨ (⍉⌽wf ⌽⍉⍵)}
+/+/sfn t
