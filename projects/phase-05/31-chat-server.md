# Project 31: Chat Server

**Module:** 5.5 — Networking and TCP/IP  
**Estimated time:** 8–10 hours

## Description

Multi-client TCP chat server. Clients connect, set a nickname, broadcast messages to all connected clients.

## Protocol (text line-based)

Client → server:

```
NICK alice
MSG hello everyone
QUIT
```

Server → client:

```
OK nick set
JOIN bob
MSG alice: hello everyone
LEAVE bob
ERR message text
```

## Usage

```bash
./chatserver -p 9000
# terminal 2:
./chatclient -h 127.0.0.1 -p 9000
```

Provide `chatclient` or document testing with `nc`.

## Requirements

- Track connected clients (linked list or dynamic array of `{fd, nick}`)
- Broadcast with mutex if using threads
- Or single-threaded `poll` loop (recommended for learning)
- Remove client on disconnect or QUIT
- Reject duplicate nicks

## Rubric

| Criterion | Points |
|-----------|--------|
| Multiple clients receive broadcasts | 30 |
| NICK/MSG/QUIT protocol works | 25 |
| Disconnect cleanup | 15 |
| No crashes on client drop | 15 |
| README with test transcript | 5 |
| Zero warnings | 10 |
| **Total** | **100** |

## Starter

Extend [echo_server_starter.c](../../labs/phase-05/echo_server_starter.c) with client list.

## Extension (Optional)

Add chat history buffer for late joiners.
