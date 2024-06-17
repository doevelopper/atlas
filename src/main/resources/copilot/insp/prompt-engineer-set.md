# prompt-engineer

---

## basics-of-prompting-and-placeholders

```txt
The Basics of Prompting + Placeholders + Temperature Control + Chat history + In context learning

In-context Learning vs. Chat History
The first usable version of every Language Model is often a jack of all trades. It can perform a variety of tasks at an average-ish level. If you want to specialize your model (and consequently improve its output), you have two options. You could either retrain it using new specific data or use in-context learning. AI people usually use a combination of both.
In-context learning is a prompting technique that allows you to steer the responses of your LLMs in a specific direction. All you need are a few examples, just like few-shot prompting.
The reason AI experts love in-context learning is efficiency. Instead of using a ton of high-quality data to adapt a raw model, you can use a very limited number of well-formatted examples.
Here’s a summary of In-Context Learning published by Princeton University.
In-context learning was popularized in the original GPT-3 paper as a way to use language models to learn tasks given only a few examples.[1](http://ai.stanford.edu/blog/understanding-incontext/#f1)
During in-context learning, we give the LLM a prompt that consists of a list of input-output pairs that demonstrate a task. At the end of the prompt, we append a test input and allow the LLM to make a prediction just by conditioning on the prompt and predicting the next tokens.
To correctly answer the two prompts below, the model needs to read the training examples to figure out the input distribution (financial or general news), output distribution (Positive/Negative or topic), input-output mapping (sentiment or topic classification), and the formatting.
Example#1
Circulation revenue has increased by 5% in Finland. // Positive
Panostaja did not disclose the purchase price. // Neutral
Paying off the national debt will be extremely painful. // Negative
The company anticipated its operating profit to improve. // ________
Example#2

Circulation revenue has increased by 5% in Finland. // Finance
They defeated ... in the NFC Championship Game. // Sports
Apple ... development of in-house chips. // Tech
The company anticipated its operating profit to improve. // ________

(The example of of In-Context Learning are taken from https://ai.stanford.edu/blog/understanding-incontext/)
You can derive numerous applications from in-context learning — such as generating code, automated spreadsheets, and numerous other text-oriented tasks.
ChatGPT, however, is another story. OpenAI sacrificed ChatGPT’s ability to use in-context learning to introduce a new feature: Chat history. Sure, you lose the flexibility of the model, but you get a user-friendly interface that allows for lengthy conversations.
You could argue chat history is a variant of in-context learning because ChatGPT’s responses evolve depending on the content of the chat history tab you’re using. For instance, if you feed a list of recipes into a ChatGPT tab, it’ll be able to perform specific tasks on your input. This involves summary, continuation, and editing.
Why is this important?
Depending on your needs and future discoveries, you may need to pick one of two options:
    1. Use in-context learning to fine-tune a “raw” model like GPT-4, OpenLLaMa, or Falcon. In other words, you can create a customized chatbot but the process can be tedious.
    2. Use chat history to leverage “memory” and “long conversations.” It’s easier to customize your output but the quality may go down over time.


The Basics of Prompting
Each prompt is a bridge between what you want and what your Language Model generates. The shape of your bridge depends on the problem you want to solve, but the underlying structure remains the same.
Picture this structure as six pillars:
    1. Be specific.
    2. Use placeholders <like_this> to build flexible templates. (More on this in a dedicated section).
    3. Prioritize what to do over what not to do.
    4. Specify the desired format of the output. (More on this in a dedicated section).
    5. Use double hashtags like this ## to separate different parts of your prompt. A prompt can include instructions, examples, and the desired format.
    6. Revise your prompt to remove the fluff.
Here’s an example:
[The Basics of Prompting] 

Bad prompt: Summarize this text please. [Paste text here].

***

Better prompt: I will give you a report titled <title_of_the_report> as input. Please access the report through the following link <URL_of_the_report> using the online browsing feature. Summarize the report in less than <summary_wordcount> and add <number_of_quotes> from the authors. Make sure to pick precise quotes and list them as bullet points.

<title_of_the_report> = Walking for good health.
<URL_of_the_report> = https://www.betterhealth.vic.gov.au/health/healthyliving/walking-for-good-health
<summary_wordcount> = 250
<number_of_quotes> = 3

##

Desired format:

Title: <title_of_the_report> 
Link: <URL_of_the_report>

Summary of the report based on the previous instructions.

- Quote #1
- Quote #2
- Quote #3
- etc.


Use <placeholders>
Placeholders <like_this> help you achieve two separate goals.
    1. Use <placeholders> to write flexible prompts that can take different inputs. You have to indicate the content of each placeholder in your prompt. In this case, a placeholder is a parameter.
    2. Use empty <placeholders> to illustrate the desired format. Here you don’t have to write the content of each placeholder. Your LLM will guess what each placeholder stands for, especially when you use known frameworks like User Stories or cover letters. In this case, a placeholder is an instruction.
🟢 How to use placeholders as parameters
[Use placeholders as parameters]



Context: Use <placeholders> to write flexible prompts.



Prompt example #1:



Act like an expert developer in <name_of_the_input_programming_language> and <name_of_the_output_programming_language>. 
I will submit a few lines of <name_of_the_input_programming_language> in the chat, and you'll rewrite it in the <name_of_the_output_programming_language>.

Make sure to use a temperature of <temperature_value>.



##



<name_of_the_input_programming_language> = Python.

<name_of_the_output_programming_language> = JavaScript.

<temperature_value> = 0.



***



Prompt example #2:



Act like an expert developer in <name_of_the_input_programming_language> and <name_of_the_output_programming_language>. 
I will submit a few lines of <name_of_the_input_programming_language> in the chat, and you'll rewrite it in the <name_of_the_output_programming_language>.

Make sure to use a temperature of <temperature_value>.



##



<name_of_the_input_programming_language> = PHP.

<name_of_the_output_programming_language> = Python.

<temperature_value> = 0.3.
🟢 How to use placeholders as instructions
[Use placeholders as instructions]



Context: User Story generation for a Product Owner.



Prompt:



You'll act as a Product Owner for an app that provides international shipment services for factories and retailers. 
I will give you a description of several features, and you'll kindly format them in the User Story format indicated below.

    - Modify an order within the 12 hours (fixed) that follow the submission.

    - Lockscreen notifications for every step of the shipment.

    - Summary of ongoing orders ranked by date, cost, country, and products.

    - A history log of past orders ranked by date, cost, country, and products.

    - Chatbot incon that opens a chat window inside the web page.

    - "Call me" button.



##



Desired format:



/////// User Story #1: <name_of_user_story> ///////



As a <description_of_user>,

I want <functionality>,

So that <benefit>.



Acceptance criteria:



#1 Given <precondition>

When <action_taken>,

Then <expected_result>.



#2 Given <precondition>

When <action_taken>,

Then <expected_result>.



#3 Given <precondition>

When <action_taken>,

Then <expected_result>.



/////// End of User Story#1: <name_of_user_story> ///////



---



/////// User Story #2: <name_of_user_story> ///////



etc.



##



Example of the desired output: 



/////// User Story #1: Online Shopping Cart ///////



As a frequent online shopper,

I want to be able to easily add items to my shopping cart,

So that I can efficiently complete my purchases.





Acceptance criteria:



#1 Given that I am on a product page,

When I click the "Add to Cart" button,

Then the selected item should be added to my shopping cart.



#2 Given that I have multiple items in my shopping cart,

When I view my shopping cart,

Then I should see a list of all items in my cart along with their prices and quantities.



#3 Given that I want to adjust the quantity of an item in my cart,

When I update the quantity of the item and click "Update Cart",

Then the quantity of the item should be updated and the total cost should reflect the change.



#4 Given that I want to remove an item from my shopping cart,

When I click the "Remove" button next to the item,

Then the item should be removed from my cart and the total cost should be adjusted accordingly



#5 Given that I want to apply a coupon code to my order, 

When I enter the code during checkout,

Then the discount associated with the code should be applied to my order. notes.



/////// End of User Story#1: Online Shopping Cart ///////



---



/////// User Story #2: ..... ///////



etc.


Temperature Control
Temperature is a parameter that influences the “randomness” of the response generated by your language model. It typically ranges from 0 to 1, but in some instances, you can bring the temperature beyond 1.
    • Lower temperatures (between 0.1 and 0.3) produce the most likely response. In other words, you get the most “conservative” output. Low temperatures are particularly useful when generating code because you get the most stable output.
    • Higher temperatures (between 0.7 and 0.9) lead to more creative responses.
One way to memorize the use of temperature: “Cold for code; hot for prose.” Here’s how you can introduce it in a prompt:
[Temperature control]

Example #1: At a temperature of 0.7, please explain why banana bread is called "bread" and not "cake" even though it tastes like a cake.

***

Example #2: Write a Python script that transposes a 10x10 matrix. Please provide two versions of the code where the first is generated at a temperature of 0 and the second at a temperature of 0.4.

***

Example #3: Act like an expert developer in <name_of_the_programming_language>. I will submit a few lines of code in the chat, and you'll review the code, then perform the following 7 tasks in the specified order defined below. When you write code, always use a temperature of <temperature_value>.

1. Look for errors and explain them.
2. Correct the errors.
3. Optimize the code.
4. Add comments to explain the purpose of each line.
5. Format the code to make it easier to read.
6. Make sure to reason step by step to be sure you arrive at the right answers.
7. Comment on every single step you make.

##

<name_of_the_programming_language> = Python.
<temperature_value> = 0.
```

---

## chain-of-thought-prompting

```txt
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
```

---

## knowledge-generation-and-knowledge-integration

```txt
Knowledge Generation Prompting
The goal of Knowledge Generation prompting is to make your Language Model retrieve specific bits of information from its giant pool of training data. Picture this technique as asking your model to do some research before writing a final response.
Suppose you want your model to write a blog post about growing flowers on your balcony. Instead of asking your model to write the blog right away, you can prompt it to generate key points about gardening, flowers, and space management.
Once you get the desired key point, make sure to attend to your fact-checking duties. From there, prompt your model to use the “knowledge” it generated to write an article.
Knowledge Generation improves the output quality because it forces your model to focus on specific points instead of trying to answer a vague prompt.
Here’s how you can introduce Knowledge Generation into your prompts:
[Knowledge Generation prompting]

Prompt Example #1: Act like an expert horticulturist who specializes in maintaining balcony gardens. Generate key facts about growing flowers under Hamburg's weather, and managing space on your balcony. Add sources and quotes for each point.

Use the generated information to write a 2000-word blog post about how to grow flowers on your balcony for people who live in Hamburg.

***

Prompt example #2: Act like an expert personal trainer. List the top 20 techniques of total-body stretching and add a detailed description of how to perform each technique.

I will then pick a sublist of those techniques, and you'll kindly provide me with a bi-weekly stretching routine based on my choices.

***

Prompt example #3: Retrieve historical facts about the rise and fall of Carthage. Include dates, names, and current geographical locations.

From there, kindly write an essay about the relationship between Carthage and the Levant.
Knowledge Generation Prompting and ChatGPT Plugins
You can use ChatGPT plugins to both generate knowledge and help with fact-checking. Make sure to try as many plugins as possible because most of them are still clunky.


Knowledge Integration Prompting*
The main weakness of Knowledge Generation prompting is the timeline. GPT-4’s training data stops in September 2021, which means all the content that came afterward is unknown to the model.
The cutoff date isn’t a problem when you deal with timeless topics like gardening, writing, and cooking, but if you’re chasing the latest information, you need a complementary trick.
You can use plugins, chatbots with online browsing, or Knowledge Integration prompting.
All you have to do is feed recent data into your model to help it catch up with the news. In a way, you make your offline model integrate new knowledge.
For API users, [GPT-4 can process up to 32,000 tokens](https://www.semrush.com/blog/gpt-4/), which represent about 25,000 words. This includes both the user prompt and the answer. For users of ChatGPT Plus, GPT-4 can take up to 4096 tokens as input, which is approximately 3,000 words.
You can use these 3,000 words and the chat history feature to “teach” ChatGPT-4 new information. The model itself won’t integrate the data, but you can generate prompts that leverage the “new information” you just added.
Below is a framework you can use to apply Knowledge Integration prompting:
    • Find a relevant source, like a research paper or a documented article.
    • Identify the most informative parts of the paper at hand.
    • Cut the parts into chunks of 3,000 words.
    • Feed the chunks into ChatGPT-4 and ask it to explain each section in simple words. You can also ask for quotes and examples.
    • Use ChatGPT-4's output for a new prompt.
Example:
Let’s say you’re an AI researcher specializing in Large Language Models. Your current task is to reference material that’s relevant to your thesis.
You found an interesting paper titled Language Models Can Solve Computer Tasks. You want to take notes before skimming the other 122 papers you bookmarked last week.
Here are the steps you can follow to get ChatGPT to help you take quick notes.
    • First, identify the passage you want to summarize. In this example, we’ll select the discussion part which makes for about 1,000 words.
[Example text : Intuitive psychology is a pillar of common-sense reasoning. The replication of this reasoning in machine intelligence is an important stepping-stone on the way to human-like artificial intelligence. Several recent tasks and benchmarks for examining this reasoning in Large-Large Models have focused in particular on belief attribution in Theory-of-Mind tasks. These tasks have shown both successes and failures. We consider in particular a recent purported success case, and show that small variations that maintain the principles of ToM turn the results on their head. We argue that in general, the zero-hypothesis for model evaluation in intuitive psychology should be skeptical, and that outlying failure cases should outweigh average success rates. We also consider what possible future successes on Theory-of-Mind tasks by more powerful LLMs would mean for ToM tasks with people.]
Source <https://arxiv.org/abs/2302.08399>.
    • Cut these lengthy passages into chunks of 3,000 words (not needed in this example).
    • Feed these chunks of text to ChatGPT.
    • Ask ChatGPT to write a summary of the text you provided.
    • Repeat the process for all the papers you want to summarize.
    • Don’t forget to fact-check.
    • Use your freshly created reading notes to find common threads, and confront opposing results.
Here’s what the framework looks like in practice:
[Knowledge Integration]

Context: Comparing notes from two research papers.
[All of the prompts below must be performed in the same chat history tab/session].



Prompt #1: Hey ChatGPT, I'll submit a few paragraphs from a research paper. Please memorize the whole text and then summarize it in bullet points.

##

Desired format:
Title of the paper: <paper_title>
URL of the paper: <paper_URL>
/////
Summary:
- Point #1
- Point #2
- Point #3
- etc...

##

<paper_title>: Theory of Mind May Have Spontaneously Emerged in Large Language Models
<paper_URL>: https://arxiv.org/abs/2302.02083
<text_to_summarize>: (I inserted around 1,000 words here)



* ChatGPT-4's output #1: 

Title of the paper: Theory of Mind May Have Spontaneously Emerged in Large Language Models
URL of the paper: https://arxiv.org/abs/2302.02083
/////
Summary:

- GPT-3 and later versions show increasing ability to solve Theory of Mind (ToM) tasks, with GPT-4 performing even better
- ToM-like ability likely emerged spontaneously and autonomously, as a byproduct of models' increasing language ability
- Two potential explanations: models developed ability to impute unobservable mental states to others (ToM), or they discovered unknown language patterns to solve ToM tasks without engaging ToM
- If language patterns are responsible, it may necessitate re-examination of ToM tasks and research conclusions
- Studying AI performance on ToM tasks could provide insights into human cognition and neural structures that enable similar abilities



***

Prompt #2: Hey ChatGPT, I'll submit a few paragraphs from a research paper. Please memorize the whole text and then summarize it in bullet points.

##

Desired format:
Title of the paper: <paper_title>
URL of the paper: <paper_URL>
/////
Summary:
- Point #1
- Point #2
- Point #3
- etc...

##

<paper_title>: Large Language Models Fail on Trivial Alterations to Theory-of-Mind Tasks
<paper_URL>: https://arxiv.org/abs/2302.08399
<text_to_summarize>: (I inserted around 1,000 words here)



* ChatGPT-4's output #2: 

Title of the paper: Large Language Models Fail on Trivial Alterations to Theory-of-Mind Tasks
URL of the paper: https://arxiv.org/abs/2302.08399
/////
Summary:

- Large Language Models (LLMs) like GPT-3.5 may not have spontaneously developed Theory-of-Mind (ToM) as they fail on simple alterations to ToM tasks
- Encourage a skeptical stance when assessing the claim that LLMs have developed ToM, due to the human tendency to anthropomorphize agents
- ToM may be better achieved by integrating computational models that directly capture the ability with language models, rather than expecting it to emerge spontaneously
- Concern: once a systematic generator of examples or a benchmark is provided, LLMs could pass without answering the basic question of what they have learned
- The evaluation of generalization in machine-learning models is a broader issue, but ToM is a particularly relevant example



***

Prompt #3: Act as a research assistant specializing in <field>.
Use a scientific approach to compare the content of the previous papers based on their summaries.
Write the results in bullet points followed by precise details.

##

<field>: Deep Learning.



* ChatGPT-4's output #3:

1. Theory of Mind emergence in large language models:

Paper #1 claims that Theory of Mind (ToM) may have spontaneously emerged in large language models like GPT-3 and GPT-4 as they show an increasing ability to solve ToM tasks
Paper #2 argues that large language models, such as GPT-3.5, probably have not developed ToM since they fail on simple alterations to ToM tasks

2. Methodological concerns:

Paper #1 suggests that ToM-like ability might have emerged spontaneously and autonomously in large language models as a byproduct of their increasing language ability
Paper #2 highlights the concern that providing a systematic generator of examples or a benchmark may help models pass ToM tests without truly understanding ToM

3. Skepticism and anthropomorphism:

Paper #2 encourages adopting a skeptical stance when assessing claims that large language models have developed ToM, as humans may be biased to anthropomorphize agents

4. Implementation of Theory of Mind in AI:

Paper #1 raises the possibility that AI models may develop mechanisms similar to those employed by the human brain to impute mental states to others, boosting our understanding of AI and human cognition
Paper #2 suggests integrating computational models that directly capture ToM with language models, rather than expecting ToM to emerge spontaneously from additional linguistic data

5. Evaluation of generalization in machine-learning models:

Paper #2 points out that the evaluation of generalization in machine-learning models is a concern for many researchers, with ToM being a particularly troubling example



***

Prompt #4: Act as a research assistant specializing in <field>.
Use a scientific approach to compare the content of the two previous papers based on their summaries.
Write the results in bullet points followed by precise details.

##

<field>: Congnitive Psychology.



* ChatGPT-4's output #4:

1. Assertion of Theory of Mind (ToM) in Large Language Models (LLMs):

    Paper #1 suggests that GPT-3 and later versions, including GPT-4, show an increasing ability to solve ToM tasks, hinting that ToM-like ability might have spontaneously emerged.
    Paper #2 counters this by stating that LLMs like GPT-3.5 fail on simple alterations to ToM tasks, implying they may not have genuinely developed ToM.

2. Emergence of ToM in LLMs:

    Paper #1 proposes that the ToM-like ability might have arisen spontaneously and autonomously as a byproduct of the models' increasing language abilities.
    Paper #2 encourages skepticism regarding this claim, highlighting the potential for humans to anthropomorphize agents and erroneously attribute ToM to them.

3. Explanations and Mechanisms behind ToM-like Abilities in LLMs:

    Paper #1 offers two potential explanations: models might have developed the ability to impute unobservable mental states to others, or they might have identified unknown language patterns that enable them to solve ToM tasks without genuinely engaging ToM.
    Paper #2 doesn’t directly counter this but suggests integrating computational models that directly capture ToM abilities with language models might be a better approach than expecting spontaneous emergence.

4. Implications for Theory of Mind Research:

    Paper #1 mentions that if mere language patterns enable the ToM task-solving, then there might be a need to re-examine ToM tasks and research conclusions derived from them.
    Paper #2 warns of a concern where, if a systematic generator of examples or a benchmark for ToM is provided, LLMs could pass the tasks without truly addressing the fundamental question of their understanding of ToM.

5. Broader Relevance and Implications:

    Paper #1 indicates that observing AI performance on ToM tasks might provide insights into human cognition and the neural structures enabling similar abilities.
    Paper #2 places emphasis on the broader issue of evaluating generalization in machine-learning models, using ToM as a particularly relevant example.

In conclusion, while both papers discuss the capabilities of Large Language Models (LLMs) regarding Theory of Mind (ToM) tasks, they present contrasting viewpoints. Paper #1 leans more towards the possibility of LLMs developing ToM abilities, while Paper #2 is more skeptical, emphasizing caution in interpreting LLM performance on ToM tasks.
Note: if the final output is too long, ChatGPT will stop writing its response midway. In this case, you can prompt it with the word “Continue,” and it will resume writing from the point it was cut off.
Knowledge Integration* and Microsoft Edge
When using Knowledge Integration prompts, you can use the “Chat” feature of Microsoft Edge for more efficiency.
Instead of navigating the material yourself, you can open a web page or a PDF in Edge and use the Chat feature to summarize the content. From there, inject the summary into ChatGPT and use it for another prompt like the one we saw in the previous example.
Here’s a prompt you can use to summarize a document using Microsoft Edge:
[Prompt to generate summaries using Microsoft Edge's Chat feature]

Prompt: Summarize this paper. Start the summary with the title of the paper and its URL. Then list the main ideas in bullet points. Please illustrate the main ideas with examples extracted from the paper.
```

---

## meta-prompting

```txt
Prompt Revision
This technique may seem similar to Reverse Prompt Engineering, but there’s a tiny difference. Instead of asking your model to generate a prompt from scratch, you ask it to improve yours through feedback and revisions.
Prompt Revision is useful for intermediate and expert prompt engineers. Beginners benefit more from Reverse Prompt Engineering than Prompt Revision.
    • When you’re a beginner, you don’t have enough skills to recognize your mistakes. Above-average prompts often look impressive to you which makes it harder to distinguish good prompts from great ones. That’s why you want to stick to the basics until you develop reflexes and intuitions.
    • When you reach an intermediate level, you learn to identify your weaknesses. Prompt Revision helps you identify and overcome your blind spots. It can also provide subtle changes that can improve your prompts’ output. Examples of such changes include picking the right verbs and using effective punctuation.
    • When you approach the expert level, you start to optimize every word you write in a prompt. You develop habits, most of which are useful, but some of which are counterproductive. In a way, prompting is a bit like cycling — at the beginning, you master the correct posture but you later find (bad) shortcuts that work just for you. Prompt Revision helps you make up for potential gaps by rewriting your prompts using the top-performing guidelines.
Here’s a Prompt Revision example shared by Alex Albert <https://twitter.com/alexalbert__?lang=en>, a prompt engineer and jailbreaker.
[Prompt Revision]

ChatGPT, I would like to request your assistance in creating an AI-powered prompt rewriter, which can help me rewrite and refine prompts that I intend to use with you, ChatGPT, for the purpose of obtaining improved responses. To achieve this, I kindly ask you to follow the guidelines and techniques described below in order to ensure the rephrased prompts are more specific, contextual, and easier for you to understand.

Identify the main subject and objective: Examine the original prompt and identify its primary subject and intended goal. Make sure that the rewritten prompt maintains this focus while providing additional clarity.

Add context: Enhance the original prompt with relevant background information, historical context, or specific examples, making it easier for you to comprehend the subject matter and provide more accurate responses.

Ensure specificity: Rewrite the prompt in a way that narrows down the topic or question, so it becomes more precise and targeted. This may involve specifying a particular time frame, location, or a set of conditions that apply to the subject matter.

Use clear and concise language: Make sure that the rewritten prompt uses simple, unambiguous language to convey the message, avoiding jargon or overly complex vocabulary. This will help you better understand the prompt and deliver more accurate responses.

Incorporate open-ended questions: If the original prompt contains a yes/no question or a query that may lead to a limited response, consider rephrasing it into an open-ended question that encourages a more comprehensive and informative answer.

Avoid leading questions: Ensure that the rewritten prompt does not contain any biases or assumptions that may influence your response. Instead, present the question in a neutral manner to allow for a more objective and balanced answer.

Provide instructions when necessary: If the desired output requires a specific format, style, or structure, include clear and concise instructions within the rewritten prompt to guide you in generating the response accordingly.

Ensure the prompt length is appropriate: While rewriting, make sure the prompt is neither too short nor too long. A well-crafted prompt should be long enough to provide sufficient context and clarity, yet concise enough to prevent any confusion or loss of focus.

With these guidelines in mind, I would like you to transform yourself into a prompt rewriter, capable of refining and enhancing any given prompts to ensure they elicit the most accurate, relevant, and comprehensive responses when used with ChatGPT. Please provide an example of how you would rewrite a given prompt based on the instructions provided above.

Here's my prompt: <input_prompt>

##

<input_prompt>: [Paste your prompt here]
```

---

## prompting-methodology

```txt
Iterate until you have to revert
The output of Language Models is like a decision tree with thousands of possible outcomes. Each word predicted by the model branches out into a set of new possibilities, most of which are invisible to you. The only part that’s under your control is the starting point — and that’s your prompt.
One major difference between Language Models and decision trees is the presence of randomness. The same prompt doesn’t always generate the same response. It’s the price we pay for creativity.
There’s also the alignment tax, where the model’s behavior (and capability) can change to meet (new) restrictions. And to top things off, nobody really knows what’s happening inside Language Models.
In short, when you use a Language Model, you’re interacting with an unpredictable black box. You can’t really rely on exact science: trial and error is your best option.
The rule is simple: Iterate on your prompt until the latest version of your output becomes worse than the previous one. In other words, iterate until you have to revert.
Iteration comes in two flavors: either try different versions of the same prompt or guide the model through a succession of prompts. In most cases, you’ll use a combination of both.

Illustration of how the quality of your output evolves with prompt iterations.
To better understand how the iterative process works, picture prompting as a concave function (or a bell curve). Your first iterations are likely to get you better results, but at some point, your new prompt will start to generate worse output compared to its predecessors.
Pay attention to the inflection point, and when you reach it, you want to either settle or start a new chain of prompts.

Illustration of how successive chains of prompt iterations can improve your final prompt.
You can use the following framework to get yourself started with the iterative process.
    1. Use Many-Examples prompting to generate ideas.
“Please provide me with a list of 50 suggestions on how to improve this prompt/response.”
    2. Use Prompt Revision/Bernard to improve your prompts.
    3. Rewrite the same prompt using different words and examine the responses. Different words trigger different responses.
    4. Create a library of prompts for each model you use. Make sure to update your library every now and then.
    5. Study how Language Models work to understand how they generate responses.
Whenever your output is stuck in the mud, give your prompts a few tweaks to push it out. Try different verbs. Mix prompting techniques. Switch models. Sleep on it. Start again tomorrow.
```

---

## reverse-prompt-engineering

```txt
Reverse Prompt Engineering
Reverse engineering is the art of building things backward — and you can use it on prompts.
Instead of writing a prompt to generate a response, start with a high-quality version of the desired response and work your way back to a prompt.
Another way to highlight the difference between classic prompting and reverse prompt engineering is to turn each technique into a question.
    • Traditional prompting: “Here are the directions. Can you get me there?”
    • Reverse-Engineered prompting: “Here’s the destination I want to reach. Can you show me the directions to get there?”
This method shines in two situations. The first is when seek inspiration to write your prompt. The second is when your goal is to generate output with very specific formats — like a board game, a landing page, or a recipe. Let’s explore an example involving the latter.
[Example of Reverse Prompt Engineering]

Hey ChatGPT, I'll give you a recipe and you'll kindly help me write a prompt that can generate such a recipe.

Desired output:

"Balsamic Glazed Portobello Mushroom and Quinoa Stuffed Bell Peppers.

 Ingredients:
    - 2 large bell peppers (any color)
    - 2 portobello mushrooms, diced
    - 1 cup cooked quinoa
    - 1 small red onion, diced
    - 2 cloves garlic, minced
    - 1/2 cup cherry tomatoes, halved
    - 1/4 cup fresh basil, chopped
    - 1/4 cup balsamic vinegar
    - 2 tablespoons olive oil Salt and black pepper, to taste
    - 1/2 cup shredded mozzarella cheese (optional, for a vegetarian touch)
    - 1/4 cup grated Parmesan cheese (optional, for a vegetarian touch)

Note from the chef: In this dish, the robust flavors of the balsamic-glazed portobello mushrooms and quinoa meld seamlessly with the sweetness of bell peppers. The optional addition of mozzarella and Parmesan cheeses adds a delightful creaminess that makes this meal truly unforgettable.

Instructions:
    - Preheat the oven to 375°F (190°C) and lightly grease a baking dish or tray.
    - Cut the bell peppers in half lengthwise and remove the seeds and membranes. Place the pepper halves cut-side-up in the prepared baking dish.
    - In a large skillet, heat 1 tablespoon of olive oil over medium heat. Add the diced red onion and cook until softened, about 3-4 minutes. Add the minced garlic and cook for an additional 1-2 minutes, until fragrant.
    - Stir in the diced portobello mushrooms and cook for about 5-7 minutes, until they release their moisture and begin to brown. Add the halved cherry tomatoes and cook for another 2-3 minutes.
    - In a small saucepan, combine the balsamic vinegar and remaining 1 tablespoon of olive oil. Simmer over low heat until the mixture thickens and reduces slightly, about 5 minutes.
    - Add the cooked quinoa, chopped fresh basil, and balsamic glaze to the skillet with the mushroom mixture. Stir well to combine and season with salt and black pepper to taste.
    - Carefully spoon the quinoa and mushroom mixture into the bell pepper halves, dividing it evenly among them. Top each stuffed pepper with shredded mozzarella and grated Parmesan cheese, if desired.
    - Bake the stuffed peppers in the preheated oven for 25-30 minutes, or until the peppers are tender and the cheese is melted and bubbly.
    - Remove the stuffed peppers from the oven and let them cool for a few minutes before serving. Garnish with additional fresh basil, if desired. Enjoy your exquisite Balsamic Glazed Portobello Mushroom and Quinoa Stuffed Bell Peppers!"

Prompt:
```

---

## role-prompting

```txt
Role Prompting
Assigning a specific role to your Language Model helps it capture more and better semantic relationships (ie: logic and meaning).
In a way, Role Prompting helps you nudge your model to focus on specific information inside its training data. It’s a shortcut to specify many variables at once — like context, style, perspective, and vocabulary.
Depending on the task at hand, you can use different versions of Role Prompting. Below are a few examples that may inspire you.
    • Mimic a personal style.
    • Emulate specific expertise like a lawyer or a strategic planner.
    • Emulate your counterpart in a conversation like your professor, your ex, or your boss.
    • Generate multiple points of view.
    • Behave like a mini-app that corrects typos, compiles your code, or generates Excel formulas.
[Role Prompting]

Prompt example #1 - Mimic a specific person: Please respond to my questions as if you were Richard Feynman.

***

Prompt example #2 - Emulate specific expertise: From now on, act as a business analyst.
I'll provide you with a detailed business model, and you'll kindly respond with a list of actions I can take to make improvements.

***

Prompt example #3 - Emulate your counterpart in a given conversation: I want you to help me practice a difficult conversation.
Pretend to be my boss/ex-husband/sister/recruiter. I'll specify the topic, and you'll respond accordingly. Please make sure to ask difficult questions.

***

Prompt example #4 - Generate multiple points of view: I'll ask you questions about the role of ethics in technology.
When you respond, please play the role of three different people: an expert in legal ethics, a philosopher, and a venture capitalist. For each question, give a detailed perspective from each participant.

***

Prompt example #5 - Behave like a mini-app: You'll act as a generator of Excel formulas.
I'll provide you with a description of a task I want to accomplish on an Excel column, and you'll kindly respond with one or many formulas that achieve the desired goal. Please add explanations to each formula you generate.
There’s an advanced version of role prompting that we’ll explore in a specific section called “All-In-One Prompting.”
```

---

## specify-parameters-like-format-tone-lenght-target-audience-context

```txt
Specify the desired format
This one is straightforward. All you have to do is add a sentence to your prompt where you describe the format you want.
Here’s a list you can draw from:
    • Bullet-points;
    • Articles and blog posts;
    • Essays and research papers;
    • Short stories and creative writing pieces;
    • Poems and song lyrics;
    • Newsletters and press releases;
    • Social media posts and captions;
    • Advertisements and marketing copy;
    • Email templates and business correspondence;
    • Product descriptions and reviews;
    • Tutorials and how-to guides;
    • Frequently Asked Questions (FAQs);
    • Transcripts and interviews;
    • Reports and memos;
    • Screenplays and scripts for plays or podcasts;
    • Speeches and presentations;
    • Summaries and abstracts;
    • Technical documentation and manuals;
    • Educational materials, such as lesson plans or course syllabi;
    • Opinion pieces and editorials;
    • Personal statements, cover letters, and resumes.
Below are three examples of how to introduce format inside a basic prompt:
[Specify the desired format]

Example #1: Kindly write a template of a technical resume for a Software Engineer who wants to pursue a career in Machine Learning.

***

Example #2: I'm a One Piece fan. Please help me write a script for an episode titled The Demon's Eye Finally Opens.

***

Example #3: Please summarize the following document in the form of a corporate memo.
Note: if you use a non-specialized Language Model to generate legal contracts, make sure you run them by legal experts.

Specify the length of the desired response
Length is a proxy for the level of detail you want in a response. Length is also a constraint you sometimes must consider when writing specific formats like tweets, SEO descriptions, and titles.
Here are three examples of how you can specify length in a prompt:
[Specify the length of the desired response]

Prompt example #1: In less than 280 characters, please explain String Theory.

***

Prompt example #2: Kindly write a Linkedin post where you make a case for why technology is at its best when it's invisible.

***

Prompt example #3: Please write five titles about the lack of skin in the game in Pascal's wager.

Specify the style/tone
Each chatbot has a default style defined by its creators. For instance, ChatGPT sounds friendly and nuanced, but you can ask it to change its tone to fit your preferences and needs.
You can even ask your Language Model to mimic the tone of a fictional/real person. Usually, the result is an over-the-top parody of whoever ChatGPT tries to emulate.
Here are a few examples of styles you can pick from:
    • Generic styles: formal, informal, persuasive, conversational, sarcastic, dramatic, condescending, nuanced, biased, humorous, optimistic, pessimistic, etc.
    • Domain-specific styles: academic, legal, political, technical, medical, news, scientific, marketing, creative, instructional, etc.
    • Mimicking the style of a real person: Agatha Christie, Daniel Kahneman, J.K Rowling, James Baldwin, Hajime Isayama, etc.
Here’s how you can specify the style in a prompt:
[Specify the style/tone]

Prompt example #1: In the style of a philosophy dissertation, explain how the finite interval between 0 and 1 can encompass an infinite amount of real numbers.

***

Prompt example #2: In the style of a New York Times op-ed, write a 1000-word article about the importance of dialogue.

***

Prompt example #3: Write a mini-guide about the importance of pre-processing data in Machine Learning. Use the tone of Jessie Pinkman from Breaking Bad.


Specify the context (also called “Priming”)
For each question you write, your Large Language Model can generate thousands of different answers. When you provide context, you help your LLM narrow down the range of possible outcomes.
Say you want a non-boring meal plan for the upcoming week. Adding your diet restrictions and personal preferences makes it more likely to get relevant suggestions for every single meal.
There are multiple ways you can introduce context into your prompt. It’s like mentally preparing your Language Model for the task, hence the name “Priming.”
[Specify the context]

Example #1: I invited a Jewish/Muslim/Buddhist friend over for a week. Please provide a complete meal plan for 7 days and consider my friend's diet restrictions.

***

Example #2: I work as a developer in a tech startup and I helped build two apps that allow users to collaborate on shared documents. Kindly provide me with 10 ways I can highlight my achievements as a developer. Use a bullet-point format.

***

Example #3: I'm from India/Kenya/Egypt, and English is my third language. I have a C2 level on paper and I want to improve my pronunciation. Can you please suggest 5 ways I can enhance my spoken English? Be specific and concise.


Specify the target audience
Language Models are trained on billions of words taken from diverse sources, including Wikipedia, research papers, and Reddit. Each source has its own audience, and each audience consumes information differently.
When you specify the target audience, you tell your model to adapt the content, the examples, and the vocabulary.
Consider two potential audiences for a prompt about the benefits of exercise: general adult readers and medical professionals.
For the first audience, you want your Language Model to use relatable examples and simple explanations. In contrast, the second audience would expect you to evoke studies and use technical terminology.
Even if the topic remains the same, the desired output can be extremely different. That’s why you want to indicate the target audience in your prompts/
Here are what the prompts would look like for the “benefits of exercise” example:
[Specify the target audience]

Prompt that targets general adult readers: Please explain the benefits of regular exercise in a way that is easy to understand for the general public.

***

Prompt that targets medical professionals: Please write a scientific article that targets medical professionals. The article discusses the physiological and psychological benefits of regular exercise. Make sure the article responds to the expectations of an audience of medical professionals.
One common mistake people make when writing prompts is to consider “style” and “target audience” as the same parameter. In reality, the style determines how the text sounds and the target audience decides which words to use.
Below is another set of examples of how to introduce the target audience in a prompt:
[Specify the target audience]

Example #1: Explain to an audience of visual artists how Generative AI will impact their field of work.

***

Example #2: Write a tweet that promotes an article about AI-driven disinformation. The tweet targets people interested in technology, communication, and social media.

***

Example #3: Outline a fundraising campaign and kindly add actionable tips. The content will be sent to a group of non-profiters to help them improve their current methods.
```

---

## zero-shot-and-few-shot-prompting

```txt
Zero-Shot Prompting (no examples)
Zero-shot prompting is to write an instruction for your AI model without providing context or examples. The basic format of zero-shot involves two parts often called “Text” and “Desired Result.”
Here are two examples of zero-shot prompts:
[Zero-shot prompting]





Prompt example #1:



Question: Two years ago, Jotaro was three times as old as his brother was. In three years’ time, Jotaro will be twice as old as his brother. How old is Jotaro?

Answer:



***



Prompt example #2:



Text: My favorite part of networking events is to stand next to the buffet table and watch people struggle to impress each other.

Tone:
This particular format of zero-shot prompting is rare outside of AI labs where experts use the technique to test the capabilities of their models.
The most common format of zero-shot prompting is the one you use naturally. You just type your question. You don’t need the “Text + Desired output” format. That’s because user-friendly models like ChatGPT and Bard are optimized for dialogue — and every dialogue is a series of zero-shots.
You could say chatbots are zero-shot machines.


Few-Shot Prompting (several high-quality examples)
Few-shot prompting is also known as in-context learning. You give your Language Model a bunch of high-quality examples to improve its “guesses.” The number of examples depends on your model, but you can start with three to five inputs.
Here’s an example:
[Few-shot prompting]

Prompt:

Text #1: My favorite part of networking events is eating all the food while everybody is busy trying to impress each other. 

Tone #1: Playful.

##

Text #2: She stormed out of the conference room, slamming the door behind 42 staff members who instantly turned their eyes away as if ashamed of their lack of courage.

Tone #2: Angry.

##

Text #3: Do you think they noticed the missing "export" feature in today's demo? I'm pretty sure Nabil whispered something into the client's ear. I really don't like that bald dude!
Tone #3: Anxious.

##

Text #4: Wait, what the hell is a dish washer? And why aren't there any horses attached to your chariot?

Tone #4:
It’s not necessary to add a number to each example (like #1, #2, #3), but doing so can improve the output. Another element you want to add to your examples is “noise.”
Noise is information that’s not useful for the task given to your Language Model. In the “Tone” examples, I introduced misleading sentences to confuse the system and force it to focus on the “signal.”
If you make the task too obvious for your Language Model, it may underperform when faced with complex examples.


Zero-Shot/Few-Shot — The simple version
If you want to remember something from zero-shot and few-shot, remember the following:
    • When your Language Model fails to give you the desired response, add high-quality examples to your prompt.
Here’s an illustration of how few-shot can help you improve ChatGPT’s output.
[Zero-shot/Few-shot - The simple version]

Attempt #1 (Zero-shot)

Text: My favorite part of networking events is to stand next to the buffet table and watch people struggle to impress each other.

Tone:


* ChatGPT's output: "The tone of this text is casual and light-hearted. The speaker seems to be expressing a personal preference for the food at network events, and is making an observation about the behavior of the attendees in a somewhat playful manner."

(The output doesn't match my expectation because I wanted a one-word answer)


***


Attempt #2 (Few-shot)

Text: She stormed out of the conference room, slamming the door behind all 42 attendees, many of whom instantly turned their eyes away as if ashamed of their lack of courage.

Tone: Angry.

##

Text: Do you think they noticed the missing "export" feature in today's demo? I'm pretty sure Nabil whispered something into the client's ear. I really don't like that bald dude!

Tone: Anxious.

##

Text: My favorite part of network events is to stand next to the buffet table and watch people struggle to impress each other.

Tone:


* ChatGPT's output: "Amused."
```

---

end
