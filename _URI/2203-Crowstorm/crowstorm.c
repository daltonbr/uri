/*

    Problem: CrowStorm #2203
    Author: Dalton Lima github @daltonbr daltonvarussa@gmail.com
    https://www.urionlinejudge.com.br/judge/en/problems/view/2203

Fiddlesticks is a champion of League of Legends, he has as his ultimate ability
 "CrowStorm", it works as follows:

First Fiddlesticks chooses a strategic location and promptly he prepares to
resurface in one direction within a certain distance, then it is rooted and
channels the ultimate by just 1.5 seconds, after that time it resurfaces 
immediately at the target site with a flock of crows flying in the around and
causing much damage.

Fiddlesticks want your help to find out if in a certain position it is possible
 to achieve an invader with his ultimate skill.

Note: Consider that Fiddlesticks always uses his ultimate exactly in the
 direction of invasor and the invader always tries to flee in the opposite 
 direction to Fiddlesticks, at a constant speed.

    ##Input

The entry consists of several lines, each line contains the following integer
values: Xf, Yf, Xi, Yi, Vi, R1 and R2(0 ≤ Xf, Yf, Xi, Yi, Vi, R1 e R2 ≤ 100),
representing respectively the coordinates of Fiddlesticks, the initial
coordinates of the invader, the speed of the invader, the ultimate of
casting radius and flight radius of crows. Consider the unit of
measurement as the meter.

    ##Output

In the output you should print for each line the 'Y' character if it is
 possible to achieve the invasor or 'N' otherwise, both followed by a line break.

Input Sample            	Output Sample
4 6 22 6 0 16 2             Y
4 6 22 6 1 16 2             N
      
*/

#include <stdio.h>
#include <math.h>           // sqrt()

// auxiliary function declaration
float magnitude(float x, float y);

int main ()
{

    const float castTime = 1.5f;
    int Xf = -1, Yf;         // Fiddlesticks coordinates
    int Xi, Yi, Vi;          // Invader's initial coordinates and speed
    int R1, R2;              // casting and "action" radius of the Ultimate

    int difX, difY;          // Vector of the difference of positions between the players
    float finalX, finalY;      // Vector of the final position of the enemy player
    int totalRange;          // R1 + R2 ; the maximum radius that the Ultimate can reach
    
    float magnitudeDif;
    float normalizedDifX, normalizedDifY;
    float finalDistanceBetweenPlayersX, finalDistanceBetweenPlayersY, finalDistanceBetweenPlayersMag;
    
    while (scanf("%d", &Xf) == 1)
    {
        scanf("%d", &Yf);
        scanf("%d", &Xi);
        scanf("%d", &Yi);
        scanf("%d", &Vi);
        scanf("%d", &R1);
        scanf("%d", &R2);

        // Calculating totalRange (since we are on a straight line)
        totalRange = R1 + R2;

        // Calculating the difference Vector (difX, difY) at the instant of the cast of the Ultimate,
        // for the fleing direction (opposite direction)
        difX = Xi - Xf;
        difY = Yi - Yf;
        
        // Normalizing this last vector
        magnitudeDif = magnitude(difX, difY);
        //printf("[Debug] Vector difference: ( %.d , %d ) Magnitude: %.3f \n", difX, difY, magnitudeDif);

        normalizedDifX = difX/magnitudeDif;
        normalizedDifY = difY/magnitudeDif;

        // Note: SPEED is a SCALAR and VELOCITY is a VECTOR unit
        // Assuming the enemy will flee at constant speed and direction (our vector difference above)
        // Let's determine the future position of the enemy when the Ultimate is ready to cast (after the castTime 1.5f)

        finalX = Xi + (normalizedDifX * castTime * Vi);
        finalY = Yi + (normalizedDifY * castTime * Vi);
        //printf("[Debug] Enemy Final Position: ( %.3f , %.3f ) \n", finalX, finalY);

        // Remember that it's possible to overshoot our target!
        
        // Let's find if the enemy is inside the Ultimate action radius (our totalRange)
        finalDistanceBetweenPlayersX = finalX - Xf;
        finalDistanceBetweenPlayersY = finalY - Yf;
        
        // Magnitude of the distance between the players
        finalDistanceBetweenPlayersMag = magnitude(finalDistanceBetweenPlayersX, finalDistanceBetweenPlayersY);
        //printf("[Debug] Final Distance Between Players: %.3f \n", finalDistanceBetweenPlayersMag);
        //printf("[Debug] Total Cast Range: %d \n", totalRange);

        if (finalDistanceBetweenPlayersMag <= totalRange)
        {
            printf("Y\n");  // Yes! Hit the enemy!
        }
        else
        {
            printf("N\n");  // No! Miss the enemy!
        }
    }   // While closing
return 0;
}

float magnitude(float x, float y)
{
    return sqrt(x*x + y*y);
}