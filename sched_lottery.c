/*SUDEEP

LOTTERY SCHEDUCLING POLICY

*/

//called when task enters runnable state
//increments nr_running variable
static void enqueue_task_lottery(struct rq *rq, struct task_struct *p, int wakeup)
{
}

//called when task is no longer in runnable state
//decrements nr_running variable
static void dequeue_task_lottery(struct rq *rq, struct task_struct *p, int sleep)
{
}

static void
requeue_lottery_entity(struct lottery_rq *lrq, struct sched_lottery_entity *lottery_se, int head)
{
}

static void requeue_task_lottery(struct rq *rq, struct task_struct *p, int head)
{
}


static void yield_task_lottery(struct rq *rq)
{
}

//checks if the task that entered runnable state should preempt the currently running task
static void check_preempt_curr_lottery(struct rq *rq, struct task_struct *p, int flags)
{
}

//chooses most appropriate task to run next
static struct task_struct *pick_next_task_lottery(struct rq *rq)
{
//check for compensation tickets
//temp iterates over lottery ready queue
//jiffies - p->prevJiffies  gives time elapsed from the last time process was given CPU
temp = queue;
list_for_each(temp,queue)
{
	p = list_entry(temp,struct task_struct, run_list);

	if((jiffies-p->prevJiffies) < 1 ) && (p->numberOfTickets > MIN_TICKETS))
		p->numberOfTickets--;
	if((jiffies-p->prevJiffies) > 10) && (p->numberOfTickets < MAX_TICKETS))
		p->numberOfTickets++;
}

//count total number of tickets
temp = queue;
list_for_each(temp,queue)
{
	p = list_entry(temp,struct task_struct, run_list);
	totalTickets += p->numberOfTickets;
}

//draw a lucky ticket randomly
do
{
	get_random_bytes(&luckyTicket,sizeof(unsigned long));
	if(totalTickets == 0)
		return NULL;
	luckyTicket = (luckyTicket % totalTickets) + 1;
}while(luckyTicket < 0);

//search for process with lucky ticket
temp = queue;
list_for_each(temp,queue)
{
	p = list_entry(temp,struct tast_struct, run_list);
	totalSoFar += p->numberOfTickets;
	if(totalSoFar >= luckyTicket)
		break;
}

	next = p;
	return next;
	


}
	
}


static void put_prev_task_lottery(struct rq *rq, struct task_struct *p)
{
}


static void set_curr_task_lottery(struct rq *rq)
{
struct task_struct *p = rq->curr;

p->se.exec_start = rq->clock;
}


static void task_tick_lottery(struct rq *rq, struct task_struct *p, int queued)
{
}

 

//This structure provides frame work to implement new scheduling class
//by using call back functions
static const struct sched_class lottery_sched_class = {

//change this
//pointer to next scheduling class in hierarchy
.next = &fair_sched_class,

//when task enters runnable state
//nr_running++
.enqueue_task = enqueue_task_lottery,
//when task needs to go to wait state
//nr_running--
.dequeue_task = dequeue_task_lottery,
.yield_task = yield_task_lottery,

//check if the task that entered runnable state should prevent current running task
.check_preempt_curr = check_preempt_curr_lottery,

//choose the next task to run from run queue
.pick_next_task = pick_next_task_lottery,
.put_prev_task = put_prev_task_lottery,

.set_curr_task = set_curr_task_lottery,
.task_tick = task_tick_lottery,

 

};