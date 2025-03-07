# HTTP Client in C

This project implements a simple HTTP client in C. The client can send HTTP GET requests to a specified URL and display the response.

## Features

- Send HTTP GET requests
- Display HTTP response headers and body
- Handle basic HTTP status codes

## Requirements

- C compiler (e.g., GCC)
- Standard C library
- Docker to serve the html file (optional)

## Installation

1. Clone the repository:

   ```sh
   git clone https://github.com/yourusername/http-client.git
   cd http-client
   ```

2. Compile using make or gcc directly:

    ```sh
    gcc -o client client.c
    ```

    or

    ```sh
    make
    ```

3. Serve the index.html file on `127.0.0.1:8080`

    ```sh
    docker run \
        --rm \
        -v `pwd`/index.html:/usr/share/nginx/html/index.html:ro \
        -p 8080:80 \
        nginx:alpine
    ```

## Usage

To run the client, use the following command:

```sh
./client
```

Currently only send the GET request to `127.0.0.1:8080`.
Can be changed in the client.c file.

## Future improvements

- Take arguments for the ip address & port
- Include DNS resolver
- Handle HTTPS
