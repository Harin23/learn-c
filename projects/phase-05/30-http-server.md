# Project 30: HTTP Server (Minimal)

**Module:** 5.5 — Networking and TCP/IP  
**Estimated time:** 8–10 hours

## Description

Minimal HTTP/1.1 server serving static files from a document root.

## Usage

```bash
httpserver -p 8080 -r ./www
curl http://127.0.0.1:8080/index.html
curl -I http://127.0.0.1:8080/
```

## Requirements

### Supported

- `GET /path HTTP/1.1`
- Paths map to files under document root (no `..` traversal — reject with 403)
- Default `/` → `/index.html`
- MIME types: html, txt, css (minimal table)
- Status codes: 200, 404, 403, 400

### Response format

```
HTTP/1.1 200 OK\r\n
Content-Length: N\r\n
Content-Type: text/html\r\n
Connection: close\r\n
\r\n
<body>
```

### Concurrency

Choose one (document in README):

- Thread per connection
- Thread pool (Project 29)
- `poll` on client fds (Module 5.6 style)

### Security

- Reject paths containing `..`
- Limit request header size (8 KB)

## Rubric

| Criterion | Points |
|-----------|--------|
| Serves static files correctly | 30 |
| 404/403 for bad paths | 15 |
| Valid HTTP/1.1 response headers | 20 |
| Concurrent clients work | 15 |
| curl test cases pass | 10 |
| Zero warnings | 10 |
| **Total** | **100** |

## Test www/

```
www/index.html
www/about.txt
```

Create sample files in project.

## Starter

[labs/phase-05/echo_server_starter.c](../../labs/phase-05/echo_server_starter.c), [http_parse_starter.c](../../labs/phase-05/http_parse_starter.c)
