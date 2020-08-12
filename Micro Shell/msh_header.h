/*
============== MicroShell Header File ==============

Project Creators: Bashier Dahman
Assignment Information: MicroShell Program
Filename: msh_header.h

*/

// Header File that will include 

// All libraries we will be using
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>

using namespace std;

/* Initializing Variables */

char buf[1024]; //Where line of input submitted by the user is stored

//Function to Execute Commands
int ex_commands(char* const command[], int input_stream) {

    //create a variable for our processid
    pid_t pid;
    int status;

    //creating our pipes
    int pipeEX[2] = { -1, -1 };

    // if an error occurs w/ our pipe with a negative number returning
    // print an error out to the screen and close
    if (pipe(pipeEX) < 0) {
        cerr << "ERROR WITH PIPE" << endl;
        perror("pipe");
        close(input_stream);
        return -1;
    }

    // create subprocess using our pid, ERROR condition
    if ((pid = fork()) < 0) {
        cerr << "ERROR WITH FORK" << endl;
        perror("fork");

        // if an error occurred, close all pipes & stream / exit
        close(pipeEX[0]);
        close(pipeEX[1]);
        close(input_stream);
        return -1;
    }

    // create subprocess using our pid, SUCCESS condition
    if (pid == 0)
    {
        // close pipe[0]
        close(pipeEX[0]);

        // dup our input stream, closing stdin, then closing input stream
        dup2(input_stream, 0);
        close(input_stream);

        // dup our pipe[1], closing stdout, then closing pipe[1]
        dup2(pipeEX[1], 1);
        close(pipeEX[1]);

        // using execvp to execute the commands w/o requiring paths 
        execvp(command[0], command);

        // print a friendly error to the user if the executable they enterred was invalid,
        // and to try again
        cerr << "Cannot execute command, please enter a valid command and try again" << endl;
        exit(127);
    }


    // closing the stream / pipe[1] and returning previous pipe[0]
    close(input_stream);
    close(pipeEX[1]);

    return pipeEX[0];

} // end of ex_func;


// "mini_shell" which will process everything we need and will be called from our actual main
int mini_shell() {

    int exitStatus = 0; //Status for if the user would like to exit the shell

    while (1) {
        //Finds the name of the user from the system and prints that out to the command line
        char* user_name = getenv("USER");
        cout << user_name << "% ";

        fflush(NULL); //Clears the output buffer, and moves the bufferData to the console

        //stay inside the loop and keep asking the user for input until the user quits the program
        while (fgets(buf, 1024, stdin)) {

            //marks the last byte of input as 0
            buf[strlen(buf) - 1] = 0;

            //initialize a boolean to check if user wants to pipe something, set to false by default until we check with user
            bool pipeExists[512];

            //initialize these arrays to NULL so anything that was stored in them gets cleared out.
            //these arrays will hold the commands that the user wants to carry out.
            char* command[512][1024] = { NULL, NULL, NULL };
            char** const my_commands[] = {
                command[0],command[1],command[2],command[3],command[4],command[5],command[6],command[7],command[8],command[9],
                command[10],command[11],command[12],command[13],command[14],command[15],command[16],command[17],command[18],command[19],
                command[20],command[21],command[22],command[23],command[24],command[25],command[26],command[27],command[28],command[29],
                command[30],command[31],command[32],command[33],command[34],command[35],command[36],command[37],command[38],command[39],
                command[40],command[41],command[42],command[43],command[44],command[45],command[46],command[47],command[48],command[49],
                command[50],command[51],command[52],command[53],command[54],command[55],command[56],command[57],command[58],command[59],
                command[60],command[61],command[62],command[63],command[64],command[65],command[66],command[67],command[68],command[69],
                command[70],command[71],command[72],command[73],command[74],command[75],command[76],command[77],command[78],command[79],
                command[80],command[81],command[82],command[83],command[84],command[85],command[86],command[87],command[88],command[89],
                command[90],command[91],command[92],command[93],command[94],command[95],command[96],command[97],command[98],command[99],
                command[100],command[101],command[102],command[103],command[104],command[105],command[106],command[107],command[108],command[109],
                command[110],command[111],command[112],command[113],command[114],command[115],command[116],command[117],command[118],command[119],
                command[120],command[121],command[122],command[123],command[124],command[125],command[126],command[127],command[128],command[129],
                command[130],command[131],command[132],command[133],command[134],command[135],command[136],command[137],command[138],command[139],
                command[140],command[141],command[142],command[143],command[144],command[145],command[146],command[147],command[148],command[149],
                command[150],command[151],command[152],command[153],command[154],command[155],command[156],command[157],command[158],command[159],
                command[160],command[161],command[162],command[163],command[164],command[165],command[166],command[167],command[168],command[169],
                command[170],command[171],command[172],command[173],command[174],command[175],command[176],command[177],command[178],command[179],
                command[180],command[181],command[182],command[183],command[184],command[185],command[186],command[187],command[188],command[189],
                command[190],command[191],command[192],command[193],command[194],command[195],command[196],command[197],command[198],command[199],
                command[200],command[201],command[202],command[203],command[204],command[205],command[206],command[207],command[208],command[209],
                command[210],command[211],command[212],command[213],command[214],command[215],command[216],command[217],command[218],command[219],
                command[220],command[221],command[222],command[223],command[224],command[225],command[226],command[227],command[228],command[229],
                command[230],command[231],command[232],command[233],command[234],command[235],command[236],command[237],command[238],command[239],
                command[240],command[241],command[242],command[243],command[244],command[245],command[246],command[247],command[248],command[249],
                command[250],command[251],command[252],command[253],command[254],command[255],command[256],command[257],command[258],command[259],
                command[260],command[261],command[262],command[263],command[264],command[265],command[266],command[267],command[268],command[269],
                command[270],command[271],command[272],command[273],command[274],command[275],command[276],command[277],command[278],command[279],
                command[280],command[281],command[282],command[283],command[284],command[285],command[286],command[287],command[288],command[289],
                command[290],command[291],command[292],command[293],command[294],command[295],command[296],command[297],command[298],command[299],
                command[300],command[301],command[302],command[303],command[304],command[305],command[306],command[307],command[308],command[309],
                command[310],command[311],command[312],command[313],command[314],command[315],command[316],command[317],command[318],command[319],
                command[320],command[321],command[322],command[323],command[324],command[325],command[326],command[327],command[328],command[329],
                command[330],command[331],command[332],command[333],command[334],command[335],command[336],command[337],command[338],command[339],
                command[340],command[341],command[342],command[343],command[344],command[345],command[346],command[347],command[348],command[349],
                command[350],command[351],command[352],command[353],command[354],command[355],command[356],command[357],command[358],command[359],
                command[360],command[361],command[362],command[363],command[364],command[365],command[366],command[367],command[368],command[369],
                command[370],command[371],command[372],command[373],command[374],command[375],command[376],command[377],command[378],command[379],
                command[380],command[381],command[382],command[383],command[384],command[385],command[386],command[387],command[388],command[389],
                command[390],command[391],command[392],command[393],command[394],command[395],command[396],command[397],command[398],command[399],
                command[400],command[401],command[402],command[403],command[404],command[405],command[406],command[407],command[408],command[409],
                command[410],command[411],command[412],command[413],command[414],command[415],command[416],command[417],command[418],command[419],
                command[420],command[421],command[422],command[423],command[424],command[425],command[426],command[427],command[428],command[429],
                command[430],command[431],command[432],command[433],command[434],command[435],command[436],command[437],command[438],command[439],
                command[440],command[441],command[442],command[443],command[444],command[445],command[446],command[447],command[448],command[449],
                command[450],command[451],command[452],command[453],command[454],command[455],command[456],command[457],command[458],command[459],
                command[460],command[461],command[462],command[463],command[464],command[465],command[466],command[467],command[468],command[469],
                command[470],command[471],command[472],command[473],command[474],command[475],command[476],command[477],command[478],command[479],
                command[480],command[481],command[482],command[483],command[484],command[485],command[486],command[487],command[488],command[489],
                command[490],command[491],command[492],command[493],command[494],command[495],command[496],command[497],command[498],command[499],
                command[500],command[510],command[502],command[503],command[504],command[505],command[506],command[507],command[508],command[509],
                command[510],NULL
            };

            //Initialize this number to zero to start save the tokens at this index 
            int index = 0;
            //Initialize the pipe index so that to be able to tell which pipe should be read into
            int pipeExistsIndex = 0;
            //A char * to hold the token saved by strtok
            char* ptr;
            ptr = strtok(buf, " \"");

            //Loop through 'buf' and save tokens accordingly
            while (ptr != NULL) {

                //If the user types exit at any moment, the program will exit gracefully and terminate 
                if (strcmp(ptr, "exit") == 0) {
                    exitStatus = 1;
                    return exitStatus;
                }

                //If ptr is equal to | user wants to pipe something so we change pipeExists at pipeExistsIndex to true
                if (strcmp(ptr, "|") == 0) {
                    pipeExists[pipeExistsIndex] = true;
                    pipeExistsIndex++;
                    //Resets the index and ptr whenever a pipe is found
                    index = 0;
                    ptr = strtok(NULL, " ");
                }

                if (!pipeExists[0]) { //When no pipes exist, the command[0] is where the pointer is stored
                    command[0][index] = ptr;
                    ptr = strtok(NULL, " ");
                    index++;
                }
                else { //When a pipe exists
                    for (int i = 0; i < 512; i++) { //Loops through all the possible indexes of pipeExists[]
                        if (pipeExists[i] && !pipeExists[i + 1]) { //Places the value of the ptr in the corresponding command array
                            command[i + 1][index] = ptr;
                            ptr = strtok(NULL, " ");
                            index++;
                        }
                    }
                }

            }

            // file descriptor variable that'll be passed as input_stream
            int save_stdin = dup(0);

            for (int i = 0; my_commands[i] != NULL; i++) { //Executes each command stored in the my_commands array

                if (my_commands[i][0] != (NULL)) { //Checks if a command at index i exists

                    // this will call the func ex_commands, and continously execute the commands the user has entered
                    // until the buf is holding nothing more
                    save_stdin = ex_commands(my_commands[i], save_stdin);

                    if (save_stdin < 0) { //save_stdin is only < 0 when an error has occured so the program exits immediately
                        exit(1);
                    }


                }

            }

            //Closing the stdin , dup save_stdin and closing it
            dup2(save_stdin, 0);
            close(save_stdin);

            //Executing the user commands
            execlp("cat", "cat", (char*)NULL);
            //Indicating the commands were not able to be executed
            cerr << "Commands not able to be executed";


        }//endwhile

        //Returns the exitStatus as 0 indicating the user would like to continue using the shell 
        return exitStatus;
    }
}
