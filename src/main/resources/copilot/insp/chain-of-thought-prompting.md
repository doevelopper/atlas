Chain of Thought Prompting
Chain of Thought (CoT) prompting means you tell your Language Model to reason step by step before arriving at a final response. It’s as if you ask your model to think out loud.
Suppose I ask you to calculate 4x3. You could instantly compute the operation inside your head and say, “12.” But if I ask you to use a “chain of thought,” you’d split your reasoning into four steps.
    1. 4x3 = 4+4+4
    2. 4+4+4 = (4+4) + 4
    3. (4+4) + 4 = 8+4
    4. 8+4 = 12
CoT prompts are typically used to solve logical riddles. The idea is to break down complex problems into smaller, more manageable questions.
Language Models predict the next token in a sequence of words, and their predictions are more accurate when they deal with common patterns found in abundance inside training data. But sometimes, you need to tap into uncommon patterns to answer uncommon questions.
Consider the following riddle: “If eggs are $0.12 a dozen, how many eggs can you get for a dollar?”
If you force ChatGPT to give an immediate response, it’ll write: ”You can get 10 dozen eggs for a dollar,” which is a wrong answer.
Now, if you ask ChatGPT to reason step by step, it gives a different answer — the right answer.
User : If eggs are $0.12 a dozen, how many eggs can you get for a dollar?
Please think step by step to make sure your arrive at the right answer.

ChatGPT : To determine how many eggs you can get for a dollar, you'll need to calculate the cost per egg and then divide one dollar by that cost. Here are the steps:

Step 1: Calculate the cost per egg.
• The price is given as $0.12 per dozen (12 eggs).
• To find the cost per egg, you need to divide the price by the number of eggs in a dozen (12).
• So, $0.12 / 12 = $0.01 per egg.

Step 2: Determine how many eggs you can get for a dollar.
• To find out how many eggs you can get for one dollar, you simply divide one dollar by the cost per egg.
• $1.00 / $0.01 per egg = 100 eggs.

So, you can get 100 eggs for one dollar if eggs are priced at $0.12 per dozen.
The latest versions of ChatGPT often (but not always) use CoT when they respond to prompts.
There are two ways you can use Chain of Thought prompting.
1. Zero-Shot Chain of Thought
Add one sentence at the end of your prompt to make your Language Model apply CoT. The top-performing sentences I found are:
    • “….Let’s think step by step.”
    • “….Please proceed step by step to be sure you arrive at the right answer.”
Here’s how you can incorporate them in your prompts:
[Zero-shot Chain of thought prompting]

Prompt example #1: If eggs are $0.12 a dozen, how many eggs can you get for a dollar?
Let's think step by step.

***

Prompt example #2: A bat and a ball cost $1.10 in total. The bat costs $1.00 more than the ball. How much does the ball cost?
Make sure to reason step by step to be sure you arrive at the right answer.
Usually, Zero-shot CoT is enough to solve logic puzzles. But if your Language Model fails, you can try the second flavor of CoT prompting.
2 . Few-Shot Chain of Thought
Much like the standard few-shot prompting, you want to feed your Language Model high-quality examples before submitting your question. Each example must include multiple steps of reasoning— and the more logical steps you add, the better the response.
Here’s an example of a prompt that combines Few-Shot and Chain of Thought:
[Example of Few-Shot Chain of Thought prompting]

Prompt:

Question #1: Walter and Skyler want to compare the duration they need to shop for groceries.
Skyler takes 30 minutes to buy her weekly groceries. Walter takes five times as long as Skyler when completing the same task. How many hours does it take Walter to buy his weekly groceries?

Answer #1: Let's break down the problem step by step. It takes Walter "30*5 = 150" minutes to climb the hill.
It takes Walter "150/60 = 2.5" hours to shop for gorceries.
So the answer is "Walter needs 2 hours and a half to buy his weekly groceries."

##

Question #2: Hanks is a baseball fan. He went out to buy a new ball and a new bat. After an exchange with the shop owner, Hanks learned it would cost him 110$ to buy the ball and the bat. He also learned the baseball bat costs 100$ more than the ball.
How much does the ball cost?

Answer #2: Let's break down the problem step by step. We will call the price of the baseball bat "B" and the price of the ball "b".
We know that "B+b = 110".
We also know that "B = b+100".
This means "b+100+b =110" which translates into"(2*b) + 100 = 110."
We can then infer that "2*b = 10" and that "b = 5."
So the answer is "The ball costs 5$."

##

Question #3: Flynn has 200 letters he must divide into 4 equal groups corresponding to 4 different cities. Each group of letters must be divided into 5 equal sub-groups.
How many letters will Flynn have in each sub-group?

Answer #3:




* ChatGPT-4's output: First, let's find out how many letters are in each group corresponding to a city. Since Flynn has 200 letters and needs to divide them into 4 equal groups, we have "200/4 = 50" letters in each group.
Now, Flynn needs to divide each group of 50 letters into 5 equal sub-groups. To do this, we divide "50/5 = 10" letters in each sub-group.
So the answer is "There will be 10 letters in each sub-group."
