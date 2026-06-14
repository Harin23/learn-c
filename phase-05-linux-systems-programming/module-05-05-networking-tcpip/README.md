# Module 5.5 — Networking and TCP/IP

**Estimated time:** 15–18 hours

## Learning Objectives

By the end of this module you will be able to:

- Explain TCP/IP layers at a practical level (socket API focus)
- Create TCP servers and clients with BSD sockets
- Use `socket`, `bind`, `listen`, `accept`, `connect`, `send`, `recv`
- Handle multiple clients with `select`/`poll` or threads
- Parse minimal HTTP/1.1 requests and send valid responses
- Build a multi-user chat server

## Prerequisites

- Completed [Module 5.4](../module-05-04-pthreads-advanced/README.md) exit criteria

## Concepts to Study

1. **Socket address structures** — `sockaddr_in`, `inet_pton`, `htons`
2. **TCP connection lifecycle** — bind/listen/accept (server), connect (client)
3. **HTTP/1.1 basics** — request line, headers, `\r\n\r\n`, body
4. **Concurrent servers** — one thread per client, pool, or multiplexing
5. **Partial reads/writes** — loops until complete message or EOF
6. **Port reuse** — `SO_REUSEADDR`
7. **UDP preview** — `SOCK_DGRAM` mention; focus on TCP here
8. **`getaddrinfo`** — modern hostname resolution

## Hands-On Labs

### Lab 1: TCP Echo Server

Accept connections; echo bytes until client closes.

Starter: [labs/phase-05/echo_server_starter.c](../../labs/phase-05/echo_server_starter.c)

### Lab 2: TCP Client

Connect to echo server; send message; print reply.

Starter: [labs/phase-05/echo_client_starter.c](../../labs/phase-05/echo_client_starter.c)

### Lab 3: Minimal HTTP Response

Parse `GET /path HTTP/1.1` from buffer; respond with 200 and HTML body.

Starter: [labs/phase-05/http_parse_starter.c](../../labs/phase-05/http_parse_starter.c)

### Lab 4: Test with curl

```bash
curl -v http://127.0.0.1:8080/
```

Document request/response headers in project README.

## Mini-Projects

1. **HTTP Server** — [projects/phase-05/30-http-server.md](../../projects/phase-05/30-http-server.md)
2. **Chat Server** — [projects/phase-05/31-chat-server.md](../../projects/phase-05/31-chat-server.md)

## Recommended Resources

| Resource | Notes |
|----------|-------|
| `man 7 ip`, `man 2 socket`, `man 2 bind`, `man 2 listen` | Primary |
| APUE / TLPI network chapters | Server patterns |
| [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/) | Free online |

## Exit Criteria

Before advancing to Module 5.6, confirm:

- [ ] Echo server/client labs work on localhost
- [ ] HTTP server returns valid response to `curl`
- [ ] Chat server relays messages between two clients
- [ ] Handles connection close without crashing
- [ ] You can explain TCP three-way handshake at high level

## Next Module

[Module 5.6 — Event-Driven Programming](../module-05-06-event-driven/README.md)
