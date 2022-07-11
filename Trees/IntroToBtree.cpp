/*Disk Structure in Hard disk drive in computer has disk structures which works on m-way Search trees
m-way search tree means their are m children of each node for ex. BST is type of m-way tree it is 2-way search tree
//?in Disk there are generally 512 bytes in one block, where as block is intersection of sector and track
ex:we have 100 entries suppose each row consist of 128 bytes so for 100 entries it will occupy 512/128=4 blocks for one row
  which means 4X25 =100 so 25 blocks will be required now for searching this we have to traverse 25 blocks which will be
  time consuming so we just create one more table with key(10 bytes),pointer(6 bytes) total 16 bytes for each row
  now this will take (512/16=32 and 100/32=3.12) approx 4 block for all info now we have to traverse only 4 blocks
  now furthur we make groups(of 4) and assign them to another pointer which again take some memory of 16 bytes which will
  take only 25/16 approx 2 blocks ...........means searching only 2 blocks we get another +block+ by that block we got our key
  means only in 4 blocks we got our answer
//!height of m-way trees is Log_m(n+1)
//!elements in tree of height h will be from minimum h to (m^h)-1
Btrees are m-way search trees with some rules
|key,pointer|--------->|key,pointer|---------------> |Id|Name|address|Info.....|Info.......
                       |key,pointer|
                       |key,pointer|
                       |key,pointer|

 //*rules for BTREES
 1. each node except Root should consist of altleast m/2 childs to m childs except leaf
 2.root should have ateast 2 childs
 3.Bottom up approach will be followed
 4.Leafs should be at same level
 5. maximum amount of key should be 2*m-1; where m-1 are values and remaning are pointers for those
 6  Element       Minimum keys
    Root            1
    Internal Nodes  ceileing(m/2)-1
 7.maximumm children of each node will be m
 8. Element       Minimum Node
    Leaf            0
    Root            2
    Internal Nodes  ceileing(m/2)

 //!minimum height of BT will be log_m(n+1)-1
 //!maximum height of BT will be log_t(n+1)/2 where t=m/2 which minimum numbers of children;
*/