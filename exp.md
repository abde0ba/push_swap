
Average approx. 510 op. for 100 numbers; and approx. 3750 op. for 500 numbers!!

Initial stage :
     - parse parameters
     - Creation of a stack A which is a doubly linked and rotating list (last.next = first; first.prec = last
     - Addition to the struct of a rank component, integer from 1 to n. This will be much more practical later.
Phase 1 :
     - Share the list into 3 (modifiable parameter in .h).
     - Push the 2 smallest thirds into stack B and do a pre-sort. Do something with others
     - Rlepeat the operation unti there are only 3 numbers left in stack A.
     - Sort these 3 numbers with a specific algorithm (2 operations maximum)
Phase2:
     (We only use the commands ra/rra/rb/rrb. sa and sb are not used in this phase)
     - Swipe B and look for the number that will take the least number of moves to push into A.
          There are each time 4 ways to bring a number from B to A: ra+rb, ra+rrb, rra+rb, rra+rrb. We are looking for the mini between these 4 ways.
     - Then carry out the operation.
     - Repeat the operation until B is empty.
Phase 3: If necessary, rotate stack A to finalize the correct order. The shorter between ra or rra.
The optimization comes from the maximum use of the double rotations rr and rrr