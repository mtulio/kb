monitor DiningPhilosophers
{
	enum State {THINKING, HUNGRY, EATING};
	State[] states = new State[5];
	Condition[] self = new Condition[5];

	public DiningPhilosophers
	{
		for(int i = 0; i < 5; i++)
			states[i] = State.THINKING;
	}
	public void takeForks(int i)
	{
		state[i] = State.HUNGRY;
		test(i);
		if(state[i] != State.EATING)
			self[i].wait;
	}
	private void test(int i)
	{
		if((state[(i + 4) % 5] != State.EATING) &&
		   (state[i] == State.HUNGRY) &&
		   (state[(i + 1) % 5] != State.EATING))
		{
			state[i] = State.EATING;
			self[i].signal;
		}
	}
}