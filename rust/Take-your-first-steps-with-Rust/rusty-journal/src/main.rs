use anyhow::anyhow;
use std::path::PathBuf;
use anyhow::Ok;
use structopt::StructOpt;
use home;

use crate::cli::Action::*;
use crate::cli::CommandLineArgs;
use crate::task::Task;


mod cli;
mod task;

fn find_default_journal_path() -> Option<PathBuf> {
    // home_dir returns Option<PathBuf>
    // now we use map() and lambda to append our default json file
    // so we build full path to our journal file
    home::home_dir().map(|mut path| {
        path.push("rusty-journal.json");
        path // return modified Option<PathBuf>
    })
}

fn main() -> anyhow::Result<()>{
    // Destructure, the fields can be used independently
    let CommandLineArgs {
        action,
        journal_file,
    } = CommandLineArgs::from_args();

    // Unpack the journal file
    let journal_file = journal_file
        .or_else(find_default_journal_path) // if -j is None, we need to search default
        .ok_or(anyhow!("Failed to find a journal file"))?;

    // Perform the actions
    match action {
        Add { text } => task::add_task(journal_file, Task::new(text)),
        Done { position } => task::complete_task(journal_file, position),
        List => task::list_tasks(journal_file),
    }?;
    Ok(())
}
