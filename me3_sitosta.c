#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	char* data;
  char no[10][20];
  int ctr1,ctr2=0,ctr3;
	int c;
  int score=0;
  FILE *f;
   
  printf("%s%c%c\n","Content-Type:text/html;charset=iso-8859-1",13,10);
  printf("<html>\n");
  printf("<title>Results</title>\n");
  printf("<body>\n");
  printf("<h3>Results</h3><br>\n");
   
  data = getenv("QUERY_STRING");

   
  if(data == NULL) {
    printf("<p>Error! Error in passing data from form to script.");
	}
  else {
		for(ctr1=0; ctr1<strlen(data);ctr1++){
			if(data[ctr1]=='='){
				ctr1++;
				if (ctr2==10){
					break;
				}
				else {
					for(ctr3=0;data[ctr1]!='&';ctr3++){
						no[ctr2][ctr3]=data[ctr1];
						ctr1++;
					}
					no[ctr2][ctr3]='\0';
					if((strcmp(no[ctr2],"ton")==0) || (strcmp(no[ctr2],"goose")==0) || (strcmp(no[ctr2],"charcoal")==0) || 
						 (strcmp(no[ctr2],"breath")==0) || (strcmp(no[ctr2],"age")==0) || (strcmp(no[ctr2],"keyboard")==0) || 
						 (strcmp(no[ctr2],"newspaper")==0) || (strcmp(no[ctr2],"teeth")==0) || (strcmp(no[ctr2],"corn")==0) || 
						 (strcmp(no[ctr2],"egg")==0)) {
						score++;
					}
					ctr2++;
				}
			}
		}
		f=fopen("essay.txt","w+");
		if(f==NULL){
			printf("Error!");
			exit(1);
		}
		while(data[ctr1] != '\0') {
			fprintf(f,"%c",data[ctr1]);
			ctr1++;
		}
		printf("<p>Data: no1=%s&no2=%s&no3=%s&no4=%s&no5=%s&no6=%s&no7=%s&no8=%s&no9=%s&no10=%s&essay=",no[0],no[1],no[2],no[3],no[4],no[5],no[6],no[7],no[8],no[9]);
		rewind(f);
		while ((c = getc(f)) != EOF){
 		putchar(c);
		}
		printf("</p><br>\n");
		rewind;
		while ((c = fgetc(f)) != EOF) {
			if (c == '+') {
				fseek(f, -1, SEEK_CUR);
				fputc(' ',f);
				fseek(f, 0, SEEK_CUR);
			}
		}
		fclose(f);
		printf("<p>Score: %d<br>", score);
}
	
  printf("<br><button onclick=""goBack()"">Back Questionnaire</button>\n");
  printf("<script>function goBack() {\n");
  printf("window.history.back();}</script>\n");
  printf("</body>\n");
  printf("</html>\n");
  return 0;
}
