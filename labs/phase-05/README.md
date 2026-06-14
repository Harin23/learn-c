# Phase 5 Labs

Hands-on starter code for Phase 5 modules.

| Lab | File/Directory | Module |
|-----|----------------|--------|
| errno | [errno_starter.c](errno_starter.c) | 5.1 |
| fork | [fork_starter.c](fork_starter.c) | 5.2 |
| exec | [exec_starter.c](exec_starter.c) | 5.2 |
| pipe + fork | [pipe_fork_starter.c](pipe_fork_starter.c) | 5.3 |
| dup2 | [dup2_starter.c](dup2_starter.c) | 5.3 |
| condition variable | [condvar_starter.c](condvar_starter.c) | 5.4 |
| thread pool | [tpool_starter/](tpool_starter/) | 5.4 |
| TCP echo server | [echo_server_starter.c](echo_server_starter.c) | 5.5 |
| TCP echo client | [echo_client_starter.c](echo_client_starter.c) | 5.5 |
| HTTP parse | [http_parse_starter.c](http_parse_starter.c) | 5.5 |
| select | [select_starter.c](select_starter.c) | 5.6 |
| inotify | [inotify_starter.c](inotify_starter.c) | 5.6 |

```bash
./scripts/verify-phase-05.sh
```

Use `strace` extensively in this phase:

```bash
strace -f -e trace=process,network,file ./your_program
```

Prerequisite: [Phase 4 exit gate](../../phase-04-linux-user-space/README.md#phase-exit-gate).
