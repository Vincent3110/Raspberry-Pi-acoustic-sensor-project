#include "comm.h"
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

void send_data_curl(double Leq[])
{
        char postdata[200]="data=", temp[30];
        int i;          //repeat a loop 8 times
        CURL *curl;
        CURLcode res;

        for(i=0; i<8; i++)
        {
        //in the sprintf function there is a ternary operator
                sprintf(temp, (i==7)?"%.2f":"%.2f;", Leq[i]);
                strcat(postdata, temp);         //append temp to postdata
        }
        printf("%s\n", postdata);
        //postdata is ready
        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();
        if(curl)
        {
                curl_easy_setopt(curl, CURLOPT_URL, URL);
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);
                res = curl_easy_perform(curl);
                if(res != CURLE_OK)
                {
                         fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
                         curl_easy_strerror(res);
                }
                curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
}


