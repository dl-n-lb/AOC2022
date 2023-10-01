input ← ⊃⎕nget '../in.txt' 1
4+≢⊃0(≠⊆⊢){c←(⊃input)[1-⍨⍵+⍳4]⋄c≢∪c}¨⍳4-⍨≢¨input
14+≢⊃0(≠⊆⊢){c←(⊃input)[1-⍨⍵+⍳14]⋄c≢∪c}¨⍳14-⍨≢¨input
