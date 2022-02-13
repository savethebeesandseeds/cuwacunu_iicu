#ifndef __CURL_UTILS__
#define __CURL_UTILS__
#include <curl/curl.h>
typedef struct curl_string {
    CURLcode res_code;
    char *ptr;
    size_t len;
}  curl_string_t;
int interpret_rest_code(CURLcode code);
void init_curl_string(curl_string_t *s);
size_t load_curl_string(void *ptr, size_t size, size_t nmemb, curl_string_t *s);
curl_string_t get_request(char *target_url);
#endif