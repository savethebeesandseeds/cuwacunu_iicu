/***************************************************************************
 *                                  _   _ __  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\___|
 *
 * Copyright (C) 1998 - 2020, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
/* <DESC>
 * Very simple HTTP GET
 * </DESC>
 */
#include <stdio.h>
#include <curl/curl.h>
#include <time.h>

int main(void)
{
  clock_t begin;
	clock_t end;
	double time_spent;
  char *target_url="http://api.binance.com/api/v1/time";
  // char *target_url="http://api.binance.com/api/v3/ticker/price?symbol=BTCUSDT";
  begin = clock();
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    // curl_easy_setopt(curl, CURLOPT_URL, target_url);
    curl_easy_setopt(curl, CURLOPT_URL, target_url);
    fprintf(stdout,"requesting : %s\n",target_url);
    /* example.com is redirected, so we tell libcurl to follow redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  end = clock();
  time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
  printf("[waka] :: request :: %f [s]\n",time_spent);
  printf("[waka] :: request :: %f [s]\n",1/time_spent);
  return 0;
}