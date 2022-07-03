#include "music.h"

int main()
{
    FILE *fp;
    int position;
    char ch, dummy;
    char str[40];
    Node *head = NULL, *pos = NULL, *current = NULL;

    fp = fopen("playlist.txt", "r");

    while ((fgets(str, sizeof(str), fp)))
        add_end(&head, str);
	fclose(fp);
    current = head;
    

    while(1)
    {
        printf("\n----------------PLAYLIST-----------------\n");
        printf("Press V: To view entire playlist.\n");
        printf("Press S: Start the player.\n");
        printf("Press J: Jump to a specific track.\n");
        printf("Press N: Next track.\n");
        printf("Press P: Previous track.\n");
        printf("Press F: First track.\n");
        printf("Press L: Last track.\n");
        printf("Press A: Add a track after an existing track.\n");
        printf("Press B: Add a track before an existing track.\n");
        printf("Press R: Remove a specific track from the list.\n");
        printf("Press O: Sort the tracks in alphabetical order.\n");
        printf("Press T: Stop the player.\n\n");

        printf("Enter your choice :\n");
        scanf("%c%c", &ch, &dummy);

        printf("\n");

        switch(ch)
        {
            case 'V':
                if(head == NULL)
                    printf("Playlist is Empty.\n");
                else
                    traverse(head);
                break;

            case 'S':                
                play(current);
                break;

            case 'J':
                if(head == NULL) 
                    printf("\nThe playlist is Empty\n");

                printf("Enter the position of the track: ");
                scanf("%d%c",&position,&dummy);
                current = search_track(head, position);

                if(current != NULL)
                    play(current);
                else
                    printf("\nThe specified track is not present in the list.\n");
                break;

            case 'N':
                if(current->next != NULL)
                {
                    current = current->next;
                    play(current);
                }
                else
                    printf("Playlist is Empty.\n");
                break;

            case 'P':
                if(current->prev != NULL)
                {
                    current = current->prev;
                    play(current);
                }
                else
                    printf("Playlist is Empty.\n");
                break;

            case 'F':
                if(head != NULL)
                {
                    current = head;
                    play(current);
                }
                else
                    printf("Playlist is Empty.\n");
                break;

            case 'L':
                if(head != NULL)
                {
                    current = head->prev;
                    play(current);
                }
                else
                    printf("Playlist is Empty.\n");
                break;

            case 'A':
                printf("\nEnter a pos: ");
                scanf("%d%c", &position, &dummy);
                printf("\nEnter a track: ");
                fgets(str, sizeof(str), stdin);
                add_after(head, position, str);
                break;

             case 'B':
                printf("\nEnter a pos: ");
                scanf("%d%c", &position, &dummy);
                printf("\nEnter a track: ");
                fgets(str, sizeof(str), stdin);
                add_before(&head, position, str);
                break;
                
            case 'R':
                printf("\nEnter a pos: ");
                scanf("%d%c", &position, &dummy);
                delete (&head, position);
                break;

            case 'O':
                sort_list(&head);
                break;
            case 'T':
                fp = fopen("playlist.txt","w");
                current = head;
                do
                {
                    fprintf(fp, "%s",current->data);
                    current = current->next;
                }while(current != head);
                fclose(fp);
                return 0;
            default :
                printf("Enter the correct choice.\n");
        
        }
    }
    fclose(fp);

    return 0;
}