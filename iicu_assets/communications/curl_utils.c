#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "curl_utils.h"
// --- --- --- --- 
int interpret_rest_code(CURLcode code){ // #FIXME no logic implemented
    if(0x00){
        fprintf(stderr,"malloc() failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    return 1;
}
// --- --- --- --- 
void init_curl_string(curl_string_t *s){
    s->len = 0;
    s->ptr = malloc(s->len+1);
    if(s->ptr == NULL){
        fprintf(stderr,"malloc() failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    s->ptr[0]='\0';
}
size_t load_curl_string(void *ptr, size_t size, size_t nmemb, curl_string_t *s){
    size_t new_len = s->len + size*nmemb;
    s->ptr = realloc(s->ptr, new_len+1);
    if(s->ptr == NULL){
        fprintf(stderr,"realloc() failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr+s->len,ptr,size*nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return size*nmemb;
}
void free_curl_string(curl_string_t *s){
    free(s->ptr);
}
curl_string_t get_request(char *target_url){
    CURL *curl;
    curl = curl_easy_init();
    curl_string_t s;
    if(curl) {
        init_curl_string(&s);

        curl_easy_setopt(curl, CURLOPT_URL, target_url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // if redirected, then we tell libcurl to follow redirection 
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, load_curl_string);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        /* Perform the request, res will get the return code */
        s.res_code = curl_easy_perform(curl);
        /* Check for errors */
        if(s.res_code != CURLE_OK)
            fprintf(stderr, "curl_utils:curl_easy_perform() failed: %s\n",
                curl_easy_strerror(s.res_code));
            
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    fprintf(stdout,"WARNING: remember to free string variable in get_request!\n");
    return s;
}


int test_conectivity(char *target_url){
    CURL *curl;
    curl = curl_easy_init();
    CURLcode res_code;
    int return_code;
    if(curl){
        return_code = STATE_STATUS_UP;
        curl_easy_setopt(curl, CURLOPT_URL, target_url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // if redirected, then we tell libcurl to follow redirection 
        /* Perform the request, res will get the return code */
        res_code = curl_easy_perform(curl);
        /* Check for errors */
        if(res_code != CURLE_OK){
            return_code = STATE_STATUS_DOWN;
            fprintf(stderr, "curl_utils:curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res_code));
        }
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    return return_code;
}