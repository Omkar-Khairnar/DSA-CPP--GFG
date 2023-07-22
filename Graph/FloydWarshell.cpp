#include <bits/stdc++.h>
 
using namespace std;

void FloydWarshell(vector<vector<int>>&matrix){
	    int n=matrix.size();

        //Assuming if there is no edge betn Vertax i and j then matrix[i][j]=Infinit(1e9);
	    //O(n^3)
	    for(int k=0; k<n; k++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                matrix[i][j]=min(matrix[i][j], matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }

        //How to deal with negative cycle
        // If (for i=0 to i=no.of vertices-1)  matrix[i][i]<0 then then there is negative edge cycle
        //Using the logic such that to reach node when src=dest the dist shoulb be zero but if it is negative then it is a negative cycle
        
	    
	
	} 
 
int main(int argc, char const *argv[])
{
 
  return 0;
}