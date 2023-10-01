res ← { 3×(3|(1+3|(⍺-⍵))) }
sum ← { (rhs⍳⍵[3]) + (rhs⍳⍵[3])res(lhs⍳⍵[1]) }
+⌿(sum¨⊃⎕NGET 'input.txt' 1)

p_sum_res ← {((rhs⍳⍵[3])-1)×3}
p_sum_played ← {((rhs⍳⍵[3])-1)×3}
get_played ← {(3 | (⍺ + ⍵ + 3)) + 1}
p_sum_played ← {(lhs ⍳ ⍵[1]) get_played (rhs ⍳ ⍵[3])}
new_sum ← {(p_sum_res ⍵) + (p_sum_played ⍵)}
+⌿(new_sum¨(⊃⎕NGET 'input.txt' 1))