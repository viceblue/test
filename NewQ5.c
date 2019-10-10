#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
int roll_dice(void);
bool play_game(void);

int main(void)
{
  int wins = 0, loses = 0;
  char ch;
  srand((unsigned)time(NULL));
  do{
    if (play_game()){
      wins++;
      printf("You win.\n");
    }
    else{
      loses++;
      printf("You lose.\n");
    }
    printf("\nPlat again? (y/n)");
    scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
printf("Wins:  %d\tLosses: %d\n\n",wins,loses);
return 0;
}



int roll_dice(void){
  int dice1, dice2;
  dice1 = rand() % 6 + 1;
  dice2 = rand() % 6 + 1;
  return (dice1 + dice2);
}

bool play_game(void){
  int dice_value, point, roll_2;
  dice_value = roll_dice();
  point = dice_value;
  printf("You rolled: %d\n",dice_value);
  if (dice_value == 2 || dice_value == 3 || dice_value == 12){
    return false;
  }
  else if (dice_value == 7 || dice_value == 11){
    return true;
    printf("You rolled: %d\n",dice_value);
  }
  else {
    printf("You point is:%d\n",dice_value);
  }
  while (1){
    roll_2 = roll_dice();
    printf("You rolled:%d\n",roll_2);
    if (roll_2 == point){
      return true;
    }
    else if (roll_2 == 7){
      return false;
    }
  }
}
