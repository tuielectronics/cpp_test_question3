# Question 3
> You are given the task of implementing a solution for the state machine outlined below.  All of the events (shown on arcs) must be processed by all states.  The default treatment for events not shown in the diagram is to log the events as "unexpected” events:

![flowchart](/Question_3/flow.png)

**Tasks:**
- Write code for the state machine.
- Add code for a 30 second timeout to the Transacting state, that changes the state back to Pending state. you may use APIs you are familiar with for this task.  Alternatively, you may define an abstract timer service.
