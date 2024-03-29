#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN       14
#define SEATS     12
#define EMPTY     0
#define TAKEN     1
#define CONTINUE  1
#define DONE      0
#define CHOICES   6

struct planestats
{
    int seat_id;
    int status;
    char last[LEN];
    char first[LEN];
};

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void makelist(const struct planestats pl[], char * str, int kind)
{
    int seat;
    char temp[LEN];

    str[0] = '\0';
    for (seat = 0; seat < SEATS; seat++)
        if (pl[seat].status == kind)
        {
            sprintf(temp, " %d", pl[seat].seat_id);
            strcat(str, temp);
        }
}

void show_seats(const struct planestats pl[], int n)
{
    int i;

    puts("Seats currently taken:");
    for (i = 0; i < SEATS; i++)
    {
        if (pl[i].status == TAKEN)
            printf("Seat %d: %s, %s\n", pl[i].seat_id,
                   pl[i].last, pl[i].first);
    }
}

void sort(struct planestats *array[], int limit)
{
    struct planestats *temp;
    for(int i = 0; i < limit - 1; ++i)
    {
        for(int j = i + 1; j < limit; ++j)
        {
            if(strcmp(array[j]->last, array[i]->last) < 0)
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

int getlet(const char *s)
{
    char c;
    c = getchar();

    while(strchr(s, c) == NULL)
    {
        printf("Please enter a character in the list %s\n", s);
        while(getchar() != '\n')
            continue;
        c = getchar();
    }
    while(getchar() != '\n')
        continue;
    return c;
}

int getmenu()
{
    const char *descript[CHOICES] = {
        "Show number of empty seats",
        "Show list of empty seats",
        "Show alphabetical list of seat assignments",
        "Assign a customer to a seat",
        "Delete a seat assignment",
        "Quit"
    };
    const char labels[CHOICES + 1] = "oeladq";
    puts("To choose a function, enter its letter label");
    for(int i = 0; i < CHOICES; ++i)
        printf("%c) %s\n", labels[i], descript[i]);
    return getlet(labels);
}

int openings(const struct planestats pl[], int n)
{
    int count = 0;
    for(int seat = 0; seat < n; ++seat)
    {
        if(pl[seat].status == EMPTY)
            count++;
    }
    return count;
}

void list_assign(struct planestats *ps[], int n)
{
    int i;
    if (openings(*ps, n) == SEATS)
        puts("All seats are empty.");
    else
    {
        sort(ps, n);
        for (i = 0; i < SEATS; i++)
            if (ps[i]->status == TAKEN)
                printf("Seat %d: %s, %s\n",
                       ps[i]->seat_id, ps[i]->last, ps[i]->first);
    }
}

void show_empties(const struct planestats pl[], int n)
{
    char seating[3 * SEATS];

    if(openings(pl, n) == 0)
        puts("All seats are assigned!");
    else
    {
        puts("The following seats are available:");
        makelist(pl, seating, EMPTY);
        puts(seating);
    }
}

void assign_seat(struct planestats pl[], int n)
{
    char list[3 * SEATS];
    int seat, loop;

    if(openings(pl, n) == 0)
        puts("All seats are assigned!");
    else
    {
        makelist(pl, list, EMPTY);
        puts("Which seat do you want? Choose from this list:");
        puts(list);
        do
        {
            while(scanf("%d", &seat) != 1)
            {
                scanf("%*s");
                puts("Please enter a number from this list:");
                puts(list);
            }
            if(seat < 1 || seat > SEATS || pl[seat - 1].status == TAKEN)
            {
                puts("Please enter a number from this list:");
                puts(list);
                loop = CONTINUE;
            }
            else
                loop = DONE;
        }while(loop == CONTINUE);
        while(getchar() != '\n')
            continue;
        puts("Please enter first name:");
        s_gets(pl[seat - 1].first, LEN);
        puts("Please enter last name:");
        s_gets(pl[seat - 1].last, LEN);
        printf("%s %s assigned to seat %d.\n", pl[seat - 1].first, pl[seat - 1].last, seat);
        puts("Please enter a to accept assignment, c to cancel it.");
        if(getlet("ac") == 'a')
        {
            pl[seat - 1].status = TAKEN;
            puts("Passenger assigned to seat.");
        }
        else
            puts("Passenger not assigned.");
    }
}

void delete_seat(struct planestats pl[], int n)
{
    int seat, loop;
    char list[3 * SEATS];

    if (openings(pl, n) == SEATS)
        puts("All seats already are empty.");
    else
    {
        show_seats(pl, n);
        makelist(pl, list, TAKEN);
        puts("Enter the number of the seat to be cancelled:");
        do
        {
            while (scanf("%d", &seat) != 1)
            {
                scanf("%*s");
                puts("Enter a number from this list:");
                puts(list);
            }
            if (seat < 1 || seat > SEATS ||
                pl[seat - 1].status == EMPTY)
            {
                puts("Enter a number from this list:");
                puts(list);
                loop = CONTINUE;
            }
            else
                loop = DONE;
        } while (loop == CONTINUE);
        while (getchar() != '\n')
            continue;
        printf("%s %s to be cancelled for seat %d.\n",
            pl[seat - 1].first, pl[seat - 1].last, seat);
        puts("Enter d to delete assignment, a to abort.");
        if (getlet("da") == 'd')
        {
            pl[seat - 1].status = EMPTY;
            puts("Passenger dropped.");
        }
        else
            puts("Passenger retained.");
    }
}

int main(void)
{
    struct planestats plane_1[SEATS], *ps[SEATS];
    int choice;
    int i;
    FILE *fp;
    size_t size = sizeof(struct planestats);

    for (i = 0; i < SEATS; i++)
        ps[i] = &plane_1[i];
    if ((fp = fopen("air.dat", "rb")) == NULL)
        for (i = 0; i < SEATS; i++)
        {
            plane_1[i].status = EMPTY;
            plane_1[i].seat_id = i + 1;
        }
    else
    {
        fread(plane_1, size, SEATS, fp);
        fclose(fp);
    }
    while ((choice = getmenu()) != 'q')
    {
        switch (choice)
        {
            case 'o': printf("There are %d empty seats.\n",
                      openings(plane_1, SEATS));
                      break;
            case 'e': show_empties(plane_1, SEATS);
                      break;
            case 'l': list_assign(ps, SEATS);
                      break;
            case 'a': assign_seat(plane_1, SEATS);
                      break;
            case 'd': delete_seat(plane_1, SEATS);
                      break;
            default : puts("Switch trouble");
                      break;
        }
    }
    if ((fp = fopen("air.dat", "wb")) == NULL)
        puts("Can't save data to file.");
    else
    {
        fwrite(plane_1, size, SEATS, fp);
        fclose(fp);
    }
    puts("Bye from Colossus Airlines!");
    return 0;
}
