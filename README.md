# 12-Month SWE → Production Systems → AI Engineering → Robotics Roadmap

**Time commitment:** 15–16 hours per week  
- Monday–Friday: 2 hours/day  
- Saturday: ~3 hours  
- Sunday: ~2–3 hours  

**Primary objective:** Build strong general SWE interview skills first, then gain hands-on cloud, DevOps, SRE, distributed systems, AI engineering, and robotics experience.

## Operating principles

- Keep DSA active throughout the full year.
- Target 6 new DSA problems and 2 re-solves each week initially.
- From Month 4, complete one timed coding assessment or mock interview every week.
- Build one evolving production-style application rather than many disconnected tutorial projects.
- Maintain a GitHub repository, error log, architecture notes, runbooks, and a project demo throughout.
- Be accurate in interviews: describe personal projects as **production-style systems you built and operated**, not as enterprise-scale production systems.

## Main portfolio project

Build an evolving **operations and fleet-management platform**.

The project will progressively include:

1. A backend API and PostgreSQL database.
2. Authentication, validation, tests, logging, caching, and background jobs.
3. Docker, CI/CD, cloud deployment, and infrastructure-as-code.
4. Metrics, traces, dashboards, alerts, incident simulations, and postmortems.
5. An AI/RAG operations copilot over documentation, runbooks, and incident reports.
6. Simulated robotics telemetry or ROS 2 integration.

---

# Phase 1 — SWE Foundations

## Month 1 — C++ fluency and problem-solving basics

### Main focus

- Modern C++ fundamentals.
- Git, Linux shell, CMake, debugging.
- Big-O analysis.
- Arrays, strings, hashing, two pointers, and prefix sums.
- Start a C++ CLI sensor/log analyzer.

### Learning goals

- C++ functions, references, `const`, vectors, strings, maps, hash maps, iterators, sorting, lambdas, file I/O, exceptions.
- Time and space complexity of common operations.
- Git commits, branches, pull requests, and README writing.

### Deliverables

- Reusable C++ coding-interview template.
- C++ CLI log/sensor-data analyzer.
- Unit tests and documented commands.
- Approximately 24 deeply reviewed DSA problems.

---

## Month 2 — Core data structures and backend foundations

### Main focus

- Binary search, intervals, stacks, queues, and linked lists.
- OOP, memory, processes, and threads.
- Python/FastAPI fundamentals.
- PostgreSQL and REST API basics.

### Learning goals

- OOP principles, stack versus heap, RAII, smart pointers, process versus thread.
- HTTP methods, REST conventions, HTTP status codes, request validation, error handling.
- SQL basics, database schema design, migrations, and CRUD operations.

### Deliverables

- Locally running FastAPI backend.
- PostgreSQL database managed with migrations.
- CRUD endpoints with validation and integration tests.
- Docker Compose local environment.
- Approximately 48 cumulative DSA problems.

---

## Month 3 — Trees, graphs, databases, and networking

### Main focus

- Trees, BFS, DFS, BSTs, heaps, graphs, topological sort, Union-Find.
- SQL joins, indexes, query plans, and transactions.
- DNS, TCP/UDP, HTTP, HTTPS, TLS, latency, timeouts, and retries.
- Improve API reliability and documentation.

### Learning goals

- Explain tree/graph traversal patterns and their complexity.
- Explain database indexes and common query-performance tradeoffs.
- Explain the path of an HTTP request from client to backend service.
- Understand idempotency, retries, caching, and rate limiting.

### Deliverables

- Improved backend with pagination, search, structured logs, and health endpoint.
- Database index experiment with documented reasoning.
- API architecture diagram.
- README, setup guide, tests, and a short project demo.
- Approximately 72 cumulative DSA problems.

---

# Phase 2 — Backend, Cloud, and Delivery

## Month 4 — Docker, testing, and interview depth

### Main focus

- Recursion, backtracking, greedy algorithms, and introductory dynamic programming.
- Docker images, containers, volumes, networking, and Docker Compose.
- Testing strategy: unit, integration, and API testing.

### Learning goals

- Write Dockerfiles efficiently.
- Understand images versus containers.
- Use environment variables safely.
- Explain test pyramid and test boundaries.
- Practice explaining DSA solutions before coding.

### Deliverables

- Fully containerized backend and database.
- Test suite running in CI.
- Linting and formatting configured.
- First weekly timed coding assessment.
- Approximately 90 cumulative DSA problems.

---

## Month 5 — Asynchronous systems and cloud deployment

### Main focus

- Dynamic programming refinement and graph revision.
- Redis caching.
- Background jobs, queues, workers, retries, and idempotency.
- Cloud fundamentals.

### Learning goals

- Explain why asynchronous processing is useful.
- Understand cache-aside strategy and cache invalidation risks.
- Learn cloud IAM, networking, compute, managed databases, object storage, secrets, and cost controls.
- Deploy a service securely with environment-based configuration.

### Deliverables

- Redis-backed cache.
- Background worker/job processing.
- First cloud deployment.
- Managed database or cloud-hosted persistence.
- Deployment documentation and cost budget.
- Approximately 105 cumulative DSA problems.

---

## Month 6 — CI/CD and infrastructure as code

### Main focus

- Mixed DSA revision and weekly coding mocks.
- GitHub Actions CI/CD.
- Deployment strategies, health checks, and rollback.
- Terraform or another infrastructure-as-code tool.

### Learning goals

- Build/test automatically on each pull request.
- Deploy safely after checks pass.
- Explain blue-green, rolling, and rollback concepts.
- Understand configuration, secrets, and least-privilege access.

### Deliverables

- CI/CD pipeline.
- Infrastructure-as-code baseline.
- Health checks and rollback instructions.
- Architecture walkthrough recording.
- Resume-ready backend/cloud project milestone.

---

# Phase 3 — Distributed Systems and SRE

## Month 7 — Observability and incident response

### Main focus

- Structured logging, metrics, distributed tracing.
- OpenTelemetry, Prometheus, Grafana, and alerting.
- SLI, SLO, error budgets, and incident management.

### Learning goals

- Distinguish logs, metrics, and traces.
- Define useful service health metrics.
- Write actionable alerts rather than noisy alerts.
- Understand incident roles, mitigation, communication, and blameless postmortems.

### Deliverables

- Metrics dashboard.
- Request tracing.
- Structured logs with correlation/request IDs.
- At least two alerts.
- Incident simulation: elevated API error rate.
- Incident simulation: database latency spike.
- Two runbooks and blameless postmortems.

---

## Month 8 — Distributed systems and Kubernetes

### Main focus

- Load balancing, caching, queues, replication, consistency, partitioning, and backpressure.
- Timeouts, retries, exponential backoff, circuit breakers, and rate limiting.
- Kubernetes fundamentals.

### Learning goals

- Explain CAP tradeoffs at an interview level.
- Explain at-least-once delivery and duplicate processing.
- Understand Kubernetes deployments, pods, services, config maps, secrets, probes, and autoscaling.
- Understand when Kubernetes is useful and when it adds unnecessary complexity.

### Deliverables

- Kubernetes deployment locally using Kind or Minikube.
- Liveness and readiness probes.
- Failure/recovery drill.
- Queue retry and duplicate-processing strategy.
- Updated architecture diagram showing distributed components.

---

# Phase 4 — AI Engineering

## Month 9 — LLM application harness and evaluation

### Main focus

- LLM application architecture.
- Model-provider abstraction.
- Prompt management and versioning.
- Structured outputs, schema validation, retries, fallbacks, and cost tracking.
- Offline evaluation datasets and regression testing.

### Learning goals

- Design prompts as versioned software artifacts.
- Validate model output before using it downstream.
- Measure relevance, correctness, latency, reliability, and token cost.
- Build a small evaluation harness with representative test cases.

### Deliverables

- LLM service integrated with the application.
- Prompt/version registry.
- Structured-output validation.
- Small gold evaluation dataset.
- Automated evaluation script.
- Model latency and cost metrics in dashboards.

---

## Month 10 — RAG built for reliability

### Main focus

- Document ingestion.
- Chunking strategies.
- Embeddings and vector search.
- Metadata filtering, hybrid search, reranking, citations, and retrieval evaluation.
- Hallucination reduction and unsupported-answer handling.

### Learning goals

- Evaluate retrieval quality separately from answer quality.
- Explain chunking and metadata tradeoffs.
- Ensure answers cite the source context.
- Design a safe response when source information is missing.

### Deliverables

- RAG operations copilot.
- Knowledge base of project documentation, runbooks, and incident reports.
- Cited answers.
- Retrieval and answer-quality evaluation.
- Document ingestion pipeline.
- RAG failure-case tests and improvement notes.

---

# Phase 5 — Robotics Specialization

## Month 11 — Robotics systems integration

### Main focus

- ROS 2 fundamentals.
- Nodes, topics, services, actions, launch files, bags, and transforms.
- Simulation and telemetry.
- One focused robotics pipeline: perception, navigation, or system health monitoring.

### Learning goals

- Explain ROS 2 communication choices.
- Work with coordinate frames and transforms.
- Build and observe a simulated robot workflow.
- Stream robotics events into the cloud platform.

### Deliverables

- ROS 2 simulation project.
- Simulated robot telemetry pipeline.
- Cloud dashboard for robot health, task success, latency, and failures.
- One focused robotics component such as OpenCV perception, navigation, or monitoring.

---

# Phase 6 — Interview and Portfolio Launch

## Month 12 — Capstone polish and interview readiness

### Main focus

- Coding mocks.
- Entry-level system-design practice.
- Behavioral interview preparation.
- Portfolio, GitHub, resume, LinkedIn, and applications.

### Learning goals

- Communicate a coding solution clearly before writing code.
- Explain system tradeoffs, reliability decisions, and incidents.
- Present each project in under five minutes.
- Answer behavioral questions using STAR.

### Deliverables

- Four to six coding mock interviews.
- Four behavioral mock interviews.
- Ten STAR stories.
- Three project walkthrough recordings.
- Polished resume and LinkedIn.
- Updated GitHub README files.
- Targeted applications for SWE, platform/backend, AI engineering, and robotics software roles.

---

# Ongoing interview preparation

## DSA target

Aim for **140–170 deeply understood problems** across the year.

Prioritize:

1. Arrays, strings, hashing.
2. Two pointers and sliding window.
3. Prefix sums and intervals.
4. Binary search.
5. Stack, queue, monotonic stack.
6. Linked lists.
7. Trees and BSTs.
8. Heaps and priority queues.
9. Graphs, BFS/DFS, shortest paths, Union-Find.
10. Recursion and backtracking.
11. Dynamic programming.
12. Greedy and bit manipulation.

For every problem:

1. Clarify assumptions.
2. State the brute-force approach.
3. Explain the optimized approach.
4. Write clean code.
5. State time and space complexity.
6. Test edge cases aloud.
7. Record mistakes in an error log.

## Behavioral story bank

Prepare ten STAR stories covering:

- A difficult bug or technical failure.
- A production-style incident simulation.
- A disagreement or conflict.
- Learning something quickly.
- A leadership example.
- Working through ambiguity.
- A project you are proud of.
- Receiving difficult feedback.
- A deadline or high-pressure situation.
- A technical tradeoff or design decision.

## Final profile

By the end of this roadmap, the goal is to be able to say:

> I am a C++-capable software engineer with strong DSA fundamentals. I have built and operated a production-style cloud application with Docker, CI/CD, observability, alerts, incident simulations, and Kubernetes exposure. I have also built an evaluated RAG/AI system and integrated software and cloud capabilities into a robotics workflow.
