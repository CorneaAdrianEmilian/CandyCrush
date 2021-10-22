# CandyCrush
Algorithm that simulates the game"CandyCrush:.\
The function will search for the biggest and closest to the left sequance of "colors" from the vector. The colors will be represented by numbers.\
If after the elimination of the group it is created another sequance of minimum 3 "colors" it will be deleted aswell. This chanelling effect it's repeated 
until there are no more sequance formed. From this point the whole process it's retaken as long as there is at least 1 sequence of minimum 3 "colors".\
>Example:\
>5 1 3 3 2 2 2 2 3 1 1 5 6 4 4 4 4 7\
>5 1 3 3 3 1 1 5 6 4 4 4 4 7\
>5 1 1 1 5 6 4 4 4 4 \
>5 5 6 4 4 4 4 7\
>5 5 6 7
